//Source : https://leetcode.com/problems/binary-tree-right-side-view/
//Author : Ayan Agrawal
//Date   : 23-07-2021

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    int max_depth=0;
    void traverse(TreeNode* root, int level)
    {
        if(root==NULL)
        {
            return;
        }
        if(level>max_depth)
        {
            max_depth = level;
            ans.push_back(root->val);
        }
        traverse(root->right,level+1);
        traverse(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        traverse(root,1);
        return ans;
    }
};