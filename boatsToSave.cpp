//Source : https://leetcode.com/problems/boats-to-save-people/
//Author : Ayan Agrawal
//Date   : 14-07-2021

class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        
        //don't just sort the string and start taking from front
        //pair lightest with heaviest 
        //If the heaviest person can share a boat with the lightest person, then do so. Otherwise, the heaviest person              can't pair with anyone, so they get their own boat.
        //The reason this works is because if the lightest person can pair with anyone, they might as well pair with the            heaviest person.
        
        int ans=0;
        int left = 0, right = a.size()-1;
        sort(a.begin(),a.end());
        while(left<=right)
        {
            ans++;
            if(a[left]+a[right]<=limit)left++;
            right--;
        }
        return ans;
    }
};