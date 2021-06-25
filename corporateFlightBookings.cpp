//Source : https://leetcode.com/problems/corporate-flight-bookings/
//Author : Ayan Agrawal
//Date   : 25-06-2021

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        //add reservations to the lasr flight in the range, 
        //and remove them before the first flight in range.
        //then use the running sum(prefix sum) to update reservations for all flights.
        
        int N = bookings.size();
        vector<int> v(n,0);
        for(int i=0; i<N; i++)
        {
            int start = bookings[i][0]-1;
            int end = bookings[i][1]-1;
            int seats = bookings[i][2];
            
            v[end] += seats;
            if(start>=1) v[start-1] -=seats;
        }
        for(int i=n-2; i>=0; i--)
        {
            v[i] += v[i+1];
        }
        return v;
    }
};