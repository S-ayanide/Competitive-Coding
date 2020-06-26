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
     void findSum(TreeNode* root, int sum, int &result)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
        {
            result += (sum+root->val);
            return;
        }
        
        findSum(root->left, (sum+root->val)*10, result);
        findSum(root->right, (sum+root->val)*10, result);
    }
    
    int sumNumbers(TreeNode* root) {
        int result = 0;
        findSum(root, 0, result);
        return result;
    }
};
