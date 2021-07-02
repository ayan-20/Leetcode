//Source : https://leetcode.com/problems/longest-common-subsequence/
//Author : Ayan Agrawal
//Date   : 2-07-2021

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(),m=text2.size();
        int dp[n+1][m+1];
        
        //initialize dp 1st row ans column by 0(as string common between null strings is null) 
        //if character of the strings match add 1.
        //else take max of remaining two.
        
        for(int i=0; i<=n; i++) dp[i][0]=0;
        for(int i=0; i<=m; i++) dp[0][i]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};