//Source : https://leetcode.com/problems/coin-change/
//Author : Ayan Agrawal
//Date   : 1-07-2021

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        //intialise first row with INT_MAX -1,(infinite coins of value 0 are needed to make sum 1,2..n.)
        //first column with 0 (Null)
        //initialise second row with j/a[0] if(j%a[0]==0) else INT_MAX-1.
        //Then Unbounded Knapsack
        
        for(int i=0; i<=n; i++) dp[i][0]=0;
        for(int i=0; i<=amount; i++) dp[0][i]=INT_MAX-1;
        
        for(int j=1; j<=amount; j++)
        {
            if(j%coins[0]==0)
            {
                dp[1][j] = j/coins[0];
            }
            else
            {
                dp[1][j] = INT_MAX-1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                if(j>=coins[i-1])
                {
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amount]<=amount) return dp[n][amount];
        else return -1;
    }
};