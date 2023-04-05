/*
Serialize a given binary tree to a file and deserialize it back to a tree.
Make sure that the original and the deserialized trees are identical.
* Serialize: Write the tree to a file.
* Deserialize: Read from a file and reconstruct the tree in memory
Serialize the tree into a list of integers, and then, deserialize it back from the list to a tree.
For simplicity’s sake, there’s no need to write the list to the files.


*/

class EduBinaryTree
{
public:
    EduBinaryTreeNode *root;
    EduBinaryTree()
    {
        root = nullptr;
    }
    EduBinaryTree(int nodeData)
    {
        root = new EduBinaryTreeNode(nodeData);
    }
    EduBinaryTree(vector<int> &v)
    {
        root = nullptr;
        for (int x : v)
        {
            Insert(x);
        }
    }
    // for BST insertion
    void Insert(int nodeData)
    {
        EduBinaryTreeNode *newNode = new EduBinaryTreeNode(nodeData);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            EduBinaryTreeNode *parent = nullptr;
            EduBinaryTreeNode *tempNode = root;
            while (tempNode != nullptr)
            {
                parent = tempNode;
                if (nodeData <= tempNode->data)
                {
                    tempNode = tempNode->left;
                }
                else
                {
                    tempNode = tempNode->right;
                }
            }
            if (nodeData <= parent->data)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
            }
        }
    }
    // FindInBstRec is a helper function used by FindInBst to
    // find the given data in the binary search tree
    EduBinaryTreeNode *FindInBstRec(EduBinaryTreeNode *node, int nodeData)
    {
        if (node == nullptr)
            return nullptr;

        if (node->data == nodeData)
        {
            return node;
        }
        else if (node->data > nodeData)
        {
            return FindInBstRec(node->left, nodeData);
        }
        else
        {
            return FindInBstRec(node->right, nodeData);
        }
    }
    // FindInBst is used to find the given data in the binary search tree
    EduBinaryTreeNode *FindInBst(int nodeData)
    {
        return FindInBstRec(root, nodeData);
    }
    // GetSubTreeNodeCount returns the count of the nodes in
    // the sub-tree rooted at the given node
    int GetSubTreeNodeCount(EduBinaryTreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + GetSubTreeNodeCount(node->left) + GetSubTreeNodeCount(node->right);
        }
    }
    // GetTreeDeepCopyRec is a helper function used by GetTreeDeepCopy
    EduBinaryTreeNode *GetTreeDeepCopyRec(EduBinaryTreeNode *node)
    {
        if (node != nullptr)
        {
            EduBinaryTreeNode *newNode = new EduBinaryTreeNode(node->data);
            newNode->left = GetTreeDeepCopyRec(node->left);
            newNode->right = GetTreeDeepCopyRec(node->right);
            return newNode;
        }
        else
        {
            return nullptr;
        }
    }
    // GetTreeDeepCopy is used to make a deep copy of the EduBinaryTree
    EduBinaryTree *GetTreeDeepCopy()
    {
        if (this->root == nullptr)
        {
            return nullptr;
        }
        else
        {
            EduBinaryTree *treeCopy = new EduBinaryTree();
            treeCopy->root = GetTreeDeepCopyRec(root);
            return treeCopy;
        }
    }
};

struct EduBinaryTreeNode
{
    int data;
    EduBinaryTreeNode *left;
    EduBinaryTreeNode *right;
    // below data member is only used for printing
    string printData;
    // below data members used only for some of the problems
    EduBinaryTreeNode *parent;
    EduBinaryTreeNode *next;
    int count;
    EduBinaryTreeNode(int d)
        : data(d),
          left(nullptr),
          right(nullptr),
          printData(to_string(d)),
          next(nullptr),
          parent(nullptr),
          count(0) {}
};


#include<queue>
#include<iostream>

vector<string> Serialize(EduBinaryTreeNode *root)
{
    vector<string> r;
    // Lets try to do by the level traversal
    queue<EduBinaryTreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            EduBinaryTreeNode* root=q.front();
            q.pop();
            if (!root)
            {
                r.push_back("null");
            } else {
            r.push_back(std::to_string(root->data));
            q.push(root->left);
            q.push(root->right);
            }
        
        }
    }
    
    return r;
}



// Function to deserialize integer list into a binary tree.
EduBinaryTreeNode *Deserialize(vector<string> &stream){
    if(stream.empty()) return nullptr;

    EduBinaryTreeNode* head=nullptr;
    queue<EduBinaryTreeNode*> q;
    string first=stream[0];
    if(first=="null") {
        head= nullptr;
    } else {
        head = new EduBinaryTreeNode(stoi(first));
    }
    q.push(head);
    for(int i=1; i<stream.size();i=i+2){
    EduBinaryTreeNode* parent = q.front();
    q.pop();

    string firstdata=stream[i];
    if(firstdata!="null") {
        parent->left= new EduBinaryTreeNode(stoi(firstdata));
        q.push(parent->left);
    }
    if (i+1<stream.size()) {
        firstdata=stream[i+1];
    if(firstdata!="null") {
        parent->right= new EduBinaryTreeNode(stoi(firstdata));
        q.push(parent->right);
    }
    }

    }
    return head;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
