//Source : https://leetcode.com/problems/gas-station/
//Author : Ayan Agrawal
//Date   : 20-06-2021

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance=0,idx=0,tank=0;
        
        for(int i=0; i<n; i++)
        {
            int consumption = gas[i]-cost[i];
            
            tank += consumption;
            if(tank<0)
            {
                idx=i+1;
                tank=0;
            }
            
            balance+=consumption;
        }
        if(balance<0) return -1;
        else return idx;
    }
};