/*
Mirror of a Tree: Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes
interchanged. 
Trees in the above figure are mirror of each other
*/

#include <iostream>
using namespace std;  


class TreeNode {
public:
  
  TreeNode* left_;
  TreeNode* right_;
  int data_;
  TreeNode(int data) : left_(0), right_(0), data_(data) {}
};


void InOrder(TreeNode* root) {
    if(!root )return;
    InOrder(root->left_);
    cout << " "  << root->data_ << " ";
    InOrder(root->right_); 
}

TreeNode* Mirror(TreeNode* root) {
    if (!root) return 0;
    TreeNode* newleft = Mirror(root->right_);
    //root->left_ = Mirror(root->right_);
    root->right_ = Mirror(root->left_);
    root->left_= newleft;
    return root;
}

int main() {

    // Lets create input;
    TreeNode* root = new TreeNode(1);
    root->left_ = new TreeNode(2);
    root->right_ = new TreeNode(3);
    root->left_->left_ = new TreeNode(4);
    root->left_->right_ = new TreeNode(5);
    
    // Lets display
    InOrder(root);

    root = Mirror(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    return 0;
}
