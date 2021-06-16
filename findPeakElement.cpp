//Source : https://leetcode.com/problems/find-peak-element/
//Author : Ayan Agrawal
//Date : 16-06-2021


/************************************************************************/


class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n==1) return 0;
        int low = 0, high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mid==0)
            {
                if(a[mid]>a[mid+1]) return mid;
                else low = mid+1;
            }
            else if(mid==n-1)
            {
                if(a[mid]>a[mid-1]) return mid;
                else high = mid-1;
            }
            else
            {
                if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return mid;
                else
                {
                    if(a[mid+1]>a[mid] && a[mid]>a[mid-1]) low=mid+1;
                    else high = mid-1;
                }
            }
        }
        return -1;
    }
};