//Source : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//Author : Ayan Agrawal
//Date   : 29-06-2021

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        
        //find index of minimum element that is not in its correct place
        //then find index of maximum element that is not in its correct place
        //(index_max)-(index_min)+1;
        
        int n = a.size();
        int mn1=INT_MAX;
        for(int i=0; i<n-1; i++)
        {
            if(a[i+1]<a[i])
            {
                mn1 = min(mn1,a[i+1]);
            }
        }
        int mx1=INT_MIN;
        for(int i=n-1; i>=1; i--)
        {
            if(a[i-1]>a[i])
            {
                mx1 = max(mx1,a[i-1]);
            }
        }
        int ans1=-1;
        for(int i=0; i<n; i++)
        {
            if(a[i]>mn1)
            {
                ans1=i;
                break;
            }
        }
        int ans2=-1;
        for(int i=n-1; i>=0; i--)
        {
            if(a[i]<mx1)
            {
                ans2=i;
                break;
            }
        }
        if(ans2==-1 && ans1==-1) return 0;
        return ans2-ans1+1;
    }
};