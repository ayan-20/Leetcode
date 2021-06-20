//Source : https://leetcode.com/problems/partition-equal-subset-sum/
//Author : Ayan Agrawal
//Date   : 20-06-2021


class Solution {
public:
    bool canPartition(vector<int>& a) {
        //0-1knapsack by observation
        //only possible if sum is even
        //find if any subset is possible with subset sum sum/2
        //other subset will be sum/2 automatically
        
        int sum = 0;
        int n = a.size();
        
        for(int i=0; i<n; i++) sum += a[i];
        
        if(sum%2) return false;
        else sum =sum/2;
        
        bool dp[n+1][sum+1];
        for(int i=0; i<=n; i++)dp[i][0]=true;
        for(int i=0; i<=sum; i++) dp[0][i]=false;
        dp[0][0]=true;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(a[i-1]<=j)
                {
                    dp[i][j] = (dp[i-1][j-a[i-1]] || dp[i][j]);
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[n][sum];
    }
};