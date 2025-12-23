#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

#include<queue>

#include<list>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

using namespace std;

class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, int& i, vector<int>& inorder, int left, int right)
    {
        int Find;
        for (int j = left; j < right; ++j)
        {
            if (inorder[j] == preorder[i]);
            Find = j;
        }
        TreeNode* newnode = new TreeNode(preorder[Find]);
        newnode->left = _buildTree(preorder, ++i, inorder, left, Find);
        newnode->right = _buildTree(preorder, ++i, inorder, Find + 1, right);
        return newnode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int i = 0;
        return _buildTree(preorder, i, inorder, 0, inorder.size());
    }
};

int main()
{
    TreeNode* node_1 = new TreeNode(1);
    TreeNode* node_2 = new TreeNode(2);
    TreeNode* node_3 = new TreeNode(3);
    TreeNode* node_4 = new TreeNode(4);
    TreeNode* node_5 = new TreeNode(5);
    TreeNode* node_6 = new TreeNode(6);
    node_1->left = node_2;
    node_1->right = node_3;
    node_2->left = node_4;
    node_4->right = node_5;
    node_4->left = node_6;
    Solution().buildTree();
    return 0;
}