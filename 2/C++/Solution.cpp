#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }

    TreeNode *reConstructBinaryTree(vector<int> pre, int startPre, int endPre, vector<int> in, int startIn, int endIn)
    {
        if (startPre > endPre || startIn > endIn)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[startPre]);

        vector <int>::iterator ite = find(in.begin(), in.end(), pre[startPre]);

        if (ite != in.end())
        {
            int index = distance(begin(in), ite);
            root->left = reConstructBinaryTree(pre, startPre + 1, index - startIn + startPre, in, startIn, index - 1);
            root->right = reConstructBinaryTree(pre, index - startIn + startPre + 1, endPre, in, index + 1, endIn);
        }
        
        return root;
    }

    void printAftTree(TreeNode *root)
    {
        if (root != NULL)
        {
            if (root->left != NULL)
            {
                printAftTree(root->left);
            }

            if (root->right != NULL)
            {
                printAftTree(root->right);
            }

            cout << root->val;
        }
    }
};

int main()
{
    int arr1[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int arr2[] = {4, 7, 2, 1, 5, 3, 8, 6};

    vector<int> pre(arr1, arr1 + 8);
    vector<int> vin(arr2, arr2 + 8);

    Solution solution;
    TreeNode *treeNode = solution.reConstructBinaryTree(pre, vin);

    //后序遍历
    solution.printAftTree(treeNode);
    return 0;
}