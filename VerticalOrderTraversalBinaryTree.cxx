/*
Find the vertical order traversal of a binary tree when the root of the binary tree is given. In other words, return the values of the nodes from top to bottom in each column, column by column from left to right.
If there is more than one node in the same column and row, return the values from left to right.
*/
#include<string>
#include<iostream>
#include<queue>
using namespace std;
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
#include<algorithm>
#include<vector>
using namespace std;

//struct cmp {
  bool cmp(pair<int,int> first, pair<int,int> second) {
    if(first.first<second.first) return true;
    return false;
  }
//};

vector<vector<int>> VerticalOrder(NodePtr root)
{
    if (!root)return {{}};
    queue<pair<int,EduBinaryTreeNode *>> q;
    q.push(pair<int,NodePtr>(0,root));
    vector<pair<int,int>> temporary;
    while (!q.empty())
    {
        size_t size = q.size();
        while (size)
        {
            pair<int,EduBinaryTreeNode *> p = q.front();
            q.pop();
            //cout << "Inserting element: " << p.first << " : " << p.second->data << endl;
            temporary.push_back(pair<int,int>(p.first,p.second->data));
            if (p.second->left)
                q.push(pair<int,NodePtr>(p.first-1,p.second->left));
            if (p.second->right)
                q.push(pair<int,NodePtr>(p.first+1,p.second->right));
            size--;
        }
    }
    
    sort(temporary.begin(),temporary.end(),cmp);
    if(!temporary.size()) return {{}};
    vector<vector<int>> result;
    vector<int>temp;
    int currLevel=temporary[0].first;
    temp.push_back(temporary[0].second);
    int currentIndex=0;
    for(int i=1; i<temporary.size();++i){
        pair<int,int> y=temporary[i];
        if(y.first!=currLevel) {
            result.push_back(temp);
            temp.clear();
            currLevel=y.first;
            temp.push_back(y.second);
        } else {
            temp.push_back(y.second);
        }
    }
    result.push_back(temp);
    return result;
}

//driver code
int main(int argc, char * argv[]) {
  // Initializing the binary tree
  std::vector < std::vector < int >> input = {
    {
      100,
      50,
      200,
      25,
      75,
      300,
      10,
      350,
      15
    },
    {
      20,
      40,
      50,
      90,
      67,
      94
    },
    {
      -10,
      -23,
      45,
      25,
      46
    },
    {
      0,
      -10,
      -5,
      3,
      6,
      4,
      8,
      5,
      70
    },
    {
      100,
      70,
      60,
      40,
      30,
      20,
      10
    }
  };

  for (int i = 0; i < input.size(); i++) {
    EduBinaryTree * tree = new EduBinaryTree(input[i]);
    std::cout << i + 1 << ".\tBinary Tree:" << std::endl;
    // Printing the tree
    //DisplayTree(tree -> root);
    std::cout << std::endl;
    std::vector < std::vector < int >> order = VerticalOrder(tree -> root);
    std::cout << "\tVertical order traversal: ";
    //PrintOrder(order);
    std::cout << "\n" << std::string(89, '-') << std::endl;
  }
}
