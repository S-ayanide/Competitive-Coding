/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = 0, rightDepth= 0;
        for(TreeNode* p=root; p; p=p->left) ++leftDepth;
        for(TreeNode* p=root; p; p=p->right) ++rightDepth;
        if (leftDepth==rightDepth) {
            return (1<< leftDepth) - 1 ;
        }
        else {
            return countNodes(root->left) + countNodes(root->right) + 1 ;
        }
    }
};
