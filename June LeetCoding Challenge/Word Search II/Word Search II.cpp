class Solution {
public:
     bool dfs(vector<vector<char>> &board, int i, int j, string word)
    {
        if(word.empty()) return true;
        int row = board.size();
        int col = board[0].size();
        char copy = board[i][j];
        board[i][j] = '~';

        string str = word.substr(1);
        if((i-1 >= 0 && board[i-1][j] == word[0] && dfs(board, i-1, j, str)) ||
           (i+1 < row && board[i+1][j] == word[0] && dfs(board, i+1, j, str)) ||
           (j-1 >= 0 && board[i][j-1] == word[0] && dfs(board, i, j-1, str)) ||
           (j+1 < col && board[i][j+1] == word[0] && dfs(board, i, j+1, str))) {
            board[i][j] = copy;
            return true;
        }
        board[i][j] = copy;
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        unordered_set<string> tmp;
        vector<string> ret;
        int row = board.size();
        if(row == 0) return vector<string>();
        int col = board[0].size();
        if(col == 0) return vector<string>();

        for(int k = 0; k < words.size(); k++)
        for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] == words[k][0] && dfs(board, i, j, words[k].substr(1)))
                tmp.insert(words[k]);
        }
        for(auto it = tmp.begin(); it != tmp.end(); ++it)
            ret.push_back(*it);
        return ret;
    }
};
