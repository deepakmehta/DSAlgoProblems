/*
Given a binary tree, connect all nodes of the same hierarchical level.
We need to connect them from left to right, so that the next pointer of each node points to the node on its immediate right.
The next pointer of the right-most node at each level will be NULL.

For this problem, each node in the binary tree has one additional pointer (the next pointer) along with the left
and right pointers.
*/
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

typedef EduBinaryTreeNode *NodePtr;

// Function to populate same level pointers
void PopulateNextPointers(NodePtr root)
{
    if (!root)return ;
    queue<EduBinaryTreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        size_t size = q.size();
        EduBinaryTreeNode* l=nullptr;
        while (size)
        {
            EduBinaryTreeNode *e = q.front();
            q.pop();
            if(l){ 
                 l->next=e;
            }
            l=e;
            if (e->left)
                q.push(e->left);
            if (e->right)
                q.push(e->right);
            size--;
        }
    }
    // Write your code here
}

// Do not modify the code below
// Function to find the given node and return its next node
EduBinaryTreeNode *GetNextNode(EduBinaryTreeNode *node, int nodeData)
{
    // Performing Binary Search
    while (node != nullptr && nodeData != node->data)
    {
        if (nodeData < node->data)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    // If node is not found return -1 else return its next node
    if (node == nullptr)
    {
        EduBinaryTreeNode *non_existing_node = new EduBinaryTreeNode(-1);
        return non_existing_node;
    }
    else
    {
        return node->next;
    }
}

string LevelOrderTraversal(EduBinaryTreeNode *root)
{
    if (!root)
        return "None";
    bool is_first = false;
    string result;
    queue<EduBinaryTreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        size_t size = q.size();
        if (is_first)
        {
            result += " : ";
        }
        is_first = true;
        bool is_firstelementinLevel = false;
        while (size)
        {
            if (is_firstelementinLevel)
            {
                result += ", ";
            }
            is_firstelementinLevel = true;
            EduBinaryTreeNode *e = q.front();
            q.pop();
            result += std::to_string(e->data);
            if (e->left)
                q.push(e->left);
            if (e->right)
                q.push(e->right);
            size--;
        }
    }
    return result;
}