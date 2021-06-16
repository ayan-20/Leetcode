//Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//Author : Ayan Agrawal
//Date   : 16-06-2021


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
    int ans,c=1;
    void traverse(TreeNode* root, int k)
    {
        if(root==NULL) return;
        traverse(root->left,k);
        if(c==k) ans=root->val;
        c++;
        traverse(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return ans;
    }
};