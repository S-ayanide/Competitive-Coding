static int x = []() {
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0; }();

class Solution {
public:
    void dfs(TreeNode* root, int val, TreeNode* &foundNode){
        if(foundNode) return;
        if(root->val==val) foundNode = root;
        if(root->left) dfs(root->left,val,foundNode);
        if(root->right) dfs(root->right,val,foundNode);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val==val) return root;
        TreeNode* foundNode(nullptr);
        dfs(root,val,foundNode);
        return foundNode;
    }
};
