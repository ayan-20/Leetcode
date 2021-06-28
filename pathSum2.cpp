//Source : https://leetcode.com/problems/path-sum-ii/
//Author : Ayan Agrawal
//Date   : 28-06-2021

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
    vector<vector<int>> arr;
    vector<int> v;
    void traverse(TreeNode* root, int targetSum)
    {
        if(root==NULL) return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(targetSum==root->val) 
            {
                arr.push_back(v);
            }
        }
        traverse(root->left,targetSum-(root->val));
        traverse(root->right,targetSum-(root->val));
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        traverse(root,targetSum);
        return arr;
    }
};