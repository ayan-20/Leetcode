class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        //Similar to printing lcs
        //This time add even if characters are not equal
        
        int n = s1.size(),m = s2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=m; i++) dp[0][i] =0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        } 
        int i=n,j=m;
        string ans;
        while(i>=1 && j>=1)
        {
            if(s1[i-1]==s2[j-1])
            {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans.push_back(s1[i-1]);
                    i--;
                }
                else
                {
                    ans.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        while(i>0) 
        {
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j>0) 
        {
            ans.push_back(s2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};