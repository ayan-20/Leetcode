//Source : https://leetcode.com/problems/maximum-subarray/
//Author : Ayan Agrawal
//Date   : 27-06-2021

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //Kadane's Algorithm
        //maintain a running maximum best_sum and a current summation max_ending_here. 
        //When we visit each num in nums, add num to max_ending_here, then update best_sum if necessary
        
        int n = nums.size();
        int max_sum_ending_here=0,c=0;
        int best_sum = INT_MIN;
        for(int i=0; i<n; i++)
        {
            max_sum_ending_here = max(nums[i], max_sum_ending_here+nums[i]);
            best_sum = max(max_sum_ending_here,best_sum);
        }
        return best_sum;
    }
};