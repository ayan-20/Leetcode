//Source : https://leetcode.com/problems/maximum-binary-tree/
//Author : Ayan Agrawal
//Date   : 21-06-2021

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
    
    //make a recursive function which constructs a tree
    //find index of maximum element in the given range
    //recursively make right subtree from right subarray and left subtree from left subarray
    
    int indexOfMax(vector<int>& nums, int start, int end)
    {
        int mx = -1;
        int j;
        for(int i=start; i<=end;  i++)
        {
            if(nums[i]>mx)
            {
                mx = nums[i];
                j = i;
            }
        }
        return j;
    }
    TreeNode* maxTree(vector<int>& nums, int start, int end)
    {
        if(start>end) return NULL;
        
        int maxIndex = indexOfMax(nums,start,end);
        
        TreeNode* root = new TreeNode(nums[maxIndex]);
        
        root ->left = maxTree(nums,start,maxIndex-1);
        root->right = maxTree(nums,maxIndex+1,end);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = maxTree(nums,0,nums.size()-1);
        return root;
    }
};