//Source : https://leetcode.com/problems/contiguous-array/
//Author : Ayan Agrawal
//Date   : 24-06-2021

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum=0;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==1) sum++;
            else sum--;
            if(mp.find(sum)==mp.end())
            {
                mp[sum] = i;
            }
            else                
            {
                ans = max(ans,i-mp[sum]);
            }
            if(sum==0) ans=max(ans,i+1);
        }
        return ans;
    }
};

//treat 0's as -1 and calculate sum at each iteration
//store the sum obtained in each iteration in a hashmap
//if sum is already present which means there is subarray in between-
//-with subarray sum 0, which implies equal 1's ans 0's.