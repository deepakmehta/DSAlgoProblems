/*
Given the root of a binary tree, return the maximum sum of any non-empty path.

A path in a binary tree is defined as follows:
A sequence of nodes in which each pair of adjacent nodes must have an edge connecting them.
A node can only be included in a path once at most.
Including the root in the path is not compulsory.
You can calculate the path sum by adding up all node values in the path. To solve this problem,
calculate the maximum path sum given the root of a binary tree so that there won’t be any greater path than it in the tree.
*/
int MaxPathSum(EduBinaryTreeNode*root, int& maximum){
    if (root == nullptr)
        return 0;
    int leftSubtree = 0;
    int rightSubtree = 0;
    // max sum on the left and right sub-trees of root
    if (MaxPathSum(root->left,maximum) > 0)
        leftSubtree = MaxPathSum(root->left,maximum);
    if (MaxPathSum(root->right,maximum) > 0)
        rightSubtree = MaxPathSum(root->right,maximum);
    // the value to start a new path where `root` is a highest root
    int valueNewPath = root->data + leftSubtree + rightSubtree;
    // update maxSum if it's better to start a new path
    maximum = std::max(maximum, valueNewPath);
    // for recursion :
    // return the max contribution if continue the same path
    return root->data + std::max(leftSubtree, rightSubtree);
}


int MaxPathSum(EduBinaryTreeNode *root){
    int sum=INT_MIN;
    MaxPathSum(root,sum);
    return sum;
}
