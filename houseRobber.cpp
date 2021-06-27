//Source : https://leetcode.com/problems/house-robber/
//Author : Ayan Agrawal
//Date   : 17-06-2021

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        //ith state of the dp will denote maximum amount of money we have robbed till now
        //either take current number and previous to previous sum or previous sum (max of them).
        
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2; i<=n; i++)
        {
            dp[i] = max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        return dp[n];
    }
};