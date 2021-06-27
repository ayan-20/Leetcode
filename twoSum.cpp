//Source : https://leetcode.com/problems/two-sum/
//Author : Ayan Agrawal
//Date   : 27-06-2021

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Use hashmap to store values of target-nums[i]
        //Because searchig takes avg O(1) in map.
        
        unordered_map<int,int> ump;
        for(int i=0; i<nums.size(); i++)
        {
            if(ump.find(target-nums[i])!=ump.end()) return {i,ump[target-nums[i]]};
            else ump[nums[i]]=i;
        }
        return {};
        
        //One Pass O(N) time Compexity
        //O(N) Space Complexity
    }
};