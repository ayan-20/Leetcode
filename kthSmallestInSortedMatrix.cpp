//Source : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//Author : Ayan Agrawal
//Date   : 07-07-2021

class Solution {
public:
    int count(vector<vector<int>>& matrix, int mid)
    {
        int n = matrix.size(),c=0;
        int m = matrix[0].size();
        int row = n-1;
        int col = 0;
        while(col<m && row>=0)
        {
            if(matrix[row][col]>mid)
            {
                row--;
            }
            else
            {
                c+= row+1;
                col++;
            }
        }
        return c;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //Binary Search on answer concept
        //bs on possible values of answer
        
        int n = matrix.size(),ans=-1;
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(count(matrix,mid)<k)      //count function counts no. of elements in matrix smaller than mid.
            {
                low = mid+1;
            }
            else
            {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};