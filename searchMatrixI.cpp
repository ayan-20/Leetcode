//Source : https://leetcode.com/problems/search-a-2d-matrix
//Author : Ayan Agrawal
//Date   : 17-06-2021


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //treat matrix as a sorted list
        //by taking care of indexes
        //n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
        //an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
        
        int m = matrix.size(), n = matrix[0].size();
        int low = 0;
        int high = n*m-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int num = matrix[mid/n][mid%n];
            if(num==target) return true;
            if(num>target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};