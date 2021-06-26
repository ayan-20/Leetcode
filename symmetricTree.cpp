//Source : https://leetcode.com/problems/symmetric-tree/
//Author : Ayan Agrawal
//Date   : 26-06-2021

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


//if values of roots of left subtree and right subtree are same
//then check recursively for every node in them

class Solution {
public:
    bool recur(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        if(root1->val!=root2->val) return false;
        else return (recur(root1->left,root2->right)&&recur(root1->right,root2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return recur(root->left,root->right);
    }
};