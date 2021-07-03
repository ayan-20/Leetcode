//Source : https://leetcode.com/problems/non-decreasing-array/
//Author : Ayan Agrawal
//Date   : 03-07-2021

class Solution {
public:
    
    //if current element is smaller than previous element
    //check if previous is greater than next one and
    //if current is greater than pos+2;
    
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(),pos=-1;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
            {
                if(pos!=-1) return false;
                pos=i;
            }
        }
        return (pos==0 || pos==-1 || pos==n-2 || nums[pos-1]<=nums[pos+1] || nums[pos]<=nums[pos+2]);
    }
};