//Source : https://leetcode.com/problems/unique-binary-search-trees/
//Author : Ayan Agrawal
//Date   : 10-07-2021

class Solution {
public:
    int numTrees(int n) {
        
        //Try to from bst with 2 node using 1 node, then 3 nodes bst using 2 node
        //observe the pattern being formed
        //Catalan No.(f(0).f(3) + f(1).f(2) + f(2).f(1) + f(3).f(0));
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++)
        {
            int r = i-1;
            for(int j=0; j<i; j++)
            {
                dp[i] += dp[j]*dp[r--];
            }
        }
        return dp[n];
    }
};