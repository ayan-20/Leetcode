//Source : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
//Author : Ayan Agrawal
//Date   : 17-06-2021


class Solution {
public:
    bool canShip(vector<int>& weights, int mid, int days){
        int n = weights.size();
        int sum=0,d=1;
        for(int i=0; i<n; i++)
        {
            if(sum+weights[i]>mid)
            {
                d++;
                sum=weights[i];
            }
            else 
            {
                sum += weights[i];
            }
        }
        return (d<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int mx=0,sum=0;
        for(int i=0; i<n; i++) 
        {
            sum += weights[i];
            mx = max(mx, weights[i]);
        }
        //binary search on the answer concept
        //checking for each value from max(weights) to sum(weights)
        //by using binary search (since it is increasing)
        int low = mx, high = sum;
        while(low<=high)
        {
            int mid = low + (high-low)/2 ;
            if(canShip(weights,mid,days)==true) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};