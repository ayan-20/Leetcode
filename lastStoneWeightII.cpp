//Source : https://leetcode.com/problems/last-stone-weight-ii/
//Author : Ayan Agrawal
//Date   : 30-06-2021

class Solution {
public:
    vector<int> subsetSum(vector<int>& stones, int sum, int n){
        bool dp[n+1][sum+1];
        for(int i=0; i<=sum; i++) dp[0][i]=false;
        for(int i=0; i<=n; i++) dp[i][0] = true;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(j>=stones[i-1])
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<=sum/2; i++)
        {
            if(dp[n][i]==true) ans.push_back(i);
        }
        return ans;
        
    }
    
    //reduce question from 2 var to 1 var as S2-S1 = sumOfArray - 2*S1
    //from range of 1 to sumOfArray check if it can be made using given array (subset sum problem)
    //then iterate through array and find min(SumOfArray - 2*S1).
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += stones[i];
        vector<int> v;
        v = subsetSum(stones,sum,n);
        int mn = INT_MAX;
        for(int i=0; i<v.size(); i++)
        {
            mn = min(mn, abs(sum-2*v[i]));
        }
        return mn;
    }
};