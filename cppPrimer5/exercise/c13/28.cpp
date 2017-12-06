#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
  public:
    TreeNode() : value(), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const string &str) : value(str), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const string &str, int c) : value(str), count(c), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &);
    ~TreeNode();

    TreeNode &operator=(const TreeNode &tn);

  private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(const TreeNode &tn)
    : value(tn.value), count(tn.count), left(nullptr), right(nullptr)
{
    if (tn.left)
    {
        left = new TreeNode(*tn.left);
    }
    if (tn.right)
    {
        right = new TreeNode(*tn.right);
    }
}

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}

TreeNode &TreeNode::operator=(const TreeNode &tn)
{
    TreeNode *tmp = nullptr;
    if (tn.left)
        tmp = new TreeNode(*tn.left);
    delete left;
    left = tmp;

    tmp = nullptr;
    if (tn.right)
        tmp = new TreeNode(*tn.right);
    delete right;
    right = tmp;

    value = tn.value;
    count = tn.count;

    return *this;
}