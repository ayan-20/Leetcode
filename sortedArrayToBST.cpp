//Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//Author : Ayan Agrawal
//Date   : 19-06-2021



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
    TreeNode* helper(vector<int>& nums, int start, int end)
    {
        if(start>end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode* new_node = new TreeNode(nums[mid]);
        new_node->left = helper(nums,start,mid-1);
        new_node->right = helper(nums,mid+1,end);
        return new_node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //mid will be root of the tree
        //middle of left subarray will be root of left subtree and so on
        //recursively make each subtree using binary search
        //by dividing array into half each time
        
        int n = nums.size();
        return helper(nums, 0, n-1);
    }
};