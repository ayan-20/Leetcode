//Source : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
//Author : Ayan Agrawal
//Date   : 06-07-2021

class Solution {
public:
    int minInsertions(string s){
        
        //Minimum Insertion/Deletion Would be same.
        //Find length of maximum palindromic subsequence and subtract from size of string
        
        int n = s.size();
        string s1=s,s2=s;
        reverse(s2.begin(),s2.end());
        int dp[n+1][n+1];
        for(int i=0; i<=n; i++)
        {
            dp[i][0]=0;
        }
        for(int i=0; i<=n; i++)
        {
            dp[0][i]=0;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (n-dp[n][n]);
    }
};