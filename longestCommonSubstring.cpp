//Source : https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//Author : Ayan Agrawal
//Date   : 04-07-2021

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        //similar to lcs but with substring
        //reinitialise dp everytime a word is not matched.
        //else add 1.
        
        int n = nums1.size();
        int m = nums2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=m; i++) dp[0][i] =0;
        for(int j=0; j<=n; j++) dp[j][0] =0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) ans = max(ans,dp[i][j]);
        return ans;
    }
};