/*
Given a binary tree, return its zigzag level order traversal.
The zigzag level order traversal corresponds to traversing nodes from left to right for one level,
and then right to left for the next level, and so on, reversing direction after every level.
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

vector<vector<int>> ZigzagLevelOrder(NodePtr root)
{
    if (!root)
        return {{}};
    bool is_first = false;
    vector<vector<int>> result;
    queue<EduBinaryTreeNode *> q;
    q.push(root);
    int levelNum = 0;
    while (!q.empty())
    {
        size_t size = q.size();
        vector<int> vec;
        while (size)
        {
            EduBinaryTreeNode *e = q.front();
            q.pop();
            vec.push_back(e->data);
            if (e->left)
                q.push(e->left);
            if (e->right)
                q.push(e->right);
            size--;
        }
        if (levelNum % 2)
            {
                reverse(vec.begin(),vec.end());
                result.push_back(vec);
            }
            else
            {
                
                result.push_back(vec);
            }
        levelNum++;
    }
    return result;
}
