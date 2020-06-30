struct TrieNode {
    string word { "" };
    array<TrieNode*, 26> chars { nullptr };
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        
        // insert words to trie
        TrieNode* root = new TrieNode();
        for (const auto& word : words) {
            auto it = root;
            for (auto c : word) {
                int idx = c - 'a';
                if (it->chars[idx] == nullptr) {
                    it->chars[idx] = new TrieNode();
                }
                it = it->chars[idx];
            }
            it->word = word;
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int idx = board[i][j] - 'a'; // convert char to idx
                if (root->chars[idx] != nullptr) {
                    search(&board, &result, i, j, root);
                }
            }
        }

        return result;
    }
private:
    void search(vector<vector<char>>* board_ptr, vector<string>* result_ptr, int i, int j, TrieNode* node) {
        // dereference pointers (avoiding non-const references)
		auto& board = *board_ptr;
        auto& result = *result_ptr;

        int idx = board[i][j] - 'a'; // convert char to idx
        node = node->chars[idx];
        if (node) {
            if (!empty(node->word)) {
				// if this is a leaf node (word exists) insert to result and unset it to avoid duplicates
                result.emplace_back(node->word);
                node->word = "";
            }

            // helper function to check for valid direction
            auto IsValidDir = [&board](int i, int j) -> bool {
                return i >= 0 && i < board.size()
                    && j >= 0 && j < board[i].size()
                    && board[i][j] != '*';
            };

			// we need to make letters as visited
            char letter = board[i][j];
            board[i][j] = '*';
			
			// check adjacent cells. we can do this in a loop, but this is faster
            if (IsValidDir(i - 1, j)) search(board_ptr, result_ptr, i - 1, j, node);
            if (IsValidDir(i + 1, j)) search(board_ptr, result_ptr, i + 1, j, node);
            if (IsValidDir(i, j - 1)) search(board_ptr, result_ptr, i, j - 1, node);
            if (IsValidDir(i, j + 1)) search(board_ptr, result_ptr, i, j + 1, node);

            board[i][j] = letter; // unmark visited
        }
    }
};
