//Source : https://leetcode.com/problems/target-sum/
//Author : Ayan Agrawal
//Date   : 30-06-2021
class Solution {
public:
    int noOfWays(vector<int>& a, int n, int num)
    {
        int dp[n+1][num+1];
        for(int i=0; i<=num; i++) dp[0][i] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=num; j++)
            {
                if(j>=a[i-1] && a[i-1]!=0) dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][num];
    }
    
    //similar to last-stone-weight-ii problem
    //as s2 - s1 = target and s1 = sum -s2
    //which means we have to only solve for (sum+target)/2
    //BEWARE of 0!!!.
    
    int findTargetSumWays(vector<int>& a, int k) {
        int n = a.size(),sum=0,c=0;
        for(int i=0; i<n; i++) 
        {
            if(a[i]==0) c++;
            sum += a[i];
        }
        if(k>sum || (k+sum)%2!=0) return 0;
        return pow(2,c)*noOfWays(a,n,(k+sum)/2);
    }
};