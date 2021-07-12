//Source : https://leetcode.com/problems/decode-ways/
//Author : Ayan Agrawal
//Date   : 12-07-2021

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        
        //ith state of dp stores no of ways uptill i to decode a msg 
        
        dp[0] = 1;
        if(s[0]=='0') dp[1]=0;
        else dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            int one_digit = (int)(s[i-1] - '0');
            int two_digit = 10*(int)(s[i-2]-'0') + one_digit;
            if(one_digit>=1)
            {
                dp[i] += dp[i-1];
            }
            if(two_digit>=10 && two_digit<=26)
            {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};