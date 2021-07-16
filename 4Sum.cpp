//Source : https://leetcode.com/problems/4sum/
//Author : Ayan Agrawal
//Date   : 16-07-2021

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        //N^2 then two pointer/Two Sum on remaining array

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                int sum = target - (nums[i]+nums[j]);
                int left = j+1, right = n-1;
                while(left<right)
                {
                    if(nums[left]+nums[right]<sum) left++;
                    else if(nums[left]+nums[right]>sum) right--;
                    else
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        ans.push_back(v);
                        
                        //checks for duplicates
                        while(left<right && nums[left]==v[2])left++;
                        
                        //checks for duplicates
                        while(left<right && nums[right]==v[3])right--;
                    }
                }
                //checks for duplicates
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            //checks for duplicates
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};