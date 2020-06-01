#include<iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution{
    public:
        Solution();
        ~Solution();
 
        void insert(int key);
        TreeNode *search(int key);
        TreeNode *invertTree(TreeNode *leaf);
        void invert();
        void displayBinTree();
        void printBinTree(TreeNode *leaf);        
        void destroy_tree();
 
    private:
        void destroy_tree(TreeNode *leaf);
        void insert(int key, TreeNode *leaf);
        TreeNode *search(int key, TreeNode *leaf);
         
        TreeNode *root;
};

Solution::Solution(){
  root=NULL;
}

Solution::~Solution(){
  destroy_tree();
}

void Solution::destroy_tree(TreeNode *leaf){
  if(leaf!=NULL){
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void Solution::insert(int key, TreeNode *leaf){
  if(key< leaf->val){
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else{
      leaf->left=new TreeNode;
      leaf->left->val=key;
      leaf->left->left=NULL;    //Sets the left child of the child TreeNode to null
      leaf->left->right=NULL;   //Sets the right child of the child TreeNode to null
    }  
  }
  else if(key>=leaf->val){
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else{
      leaf->right=new TreeNode;
      leaf->right->val=key;
      leaf->right->left=NULL;  //Sets the left child of the child TreeNode to null
      leaf->right->right=NULL; //Sets the right child of the child TreeNode to null
    }
  }
}

void Solution::invert() {
	TreeNode *newTree;
    newTree = invertTree(root);    
}

TreeNode* Solution::invertTree(TreeNode* leaf){
	if (!leaf) return leaf;
    TreeNode* temp = invertTree(leaf->left);
    leaf->left = invertTree(leaf->right);
    leaf->right = temp;
    return leaf;
}

TreeNode *Solution::search(int key, TreeNode *leaf){
  if(leaf!=NULL){
    if(key==leaf->val)
      return leaf;
    if(key<leaf->val)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

void Solution::insert(int key){
  if(root!=NULL)
    insert(key, root);
  else{
    root=new TreeNode;
    root->val=key;
    root->left=NULL;
    root->right=NULL;
  }
}

TreeNode *Solution::search(int key){
  return search(key, root);
}

void Solution::destroy_tree(){
  destroy_tree(root);
}

void Solution::displayBinTree(){
    printBinTree(root);
}
void Solution::printBinTree(TreeNode *leaf){
    if(leaf!=NULL){
        printBinTree(leaf->left);
        cout<<"  "<<leaf->val<<"     ";
        printBinTree(leaf->right);
    }
}

int main(){
	Solution b;
	b.insert(20);
	b.insert(25);
	b.insert(30);
	b.insert(22);
	b.displayBinTree();
	cout<<endl<<"Inverting"<<endl;
	b.invert();	
	b.displayBinTree();
	return 0;
}
