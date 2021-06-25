//Source : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
//Author : Ayan Agrawal
//Date   : 25-06-2021

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        //find median of the array
        //then make every element equal to the median
        
        int n = nums.size(),target,ans=0;
        sort(nums.begin(),nums.end());
        if(n%2!=0) target = nums[n/2];
        else target = (nums[n/2 -1] + nums[n/2])/2;
        for(int i=0; i<n;i++) ans += abs(target-nums[i]);
        return ans;
    }
};