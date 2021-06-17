//Source : https://leetcode.com/problems/search-a-2d-matrix-ii/
//Author : Ayan Agrawal
//Date   : 17-06-2021


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //start search from top right or bottom left
        //Lets assume top right
        // if element is small than current we can discard the bottom row and move left
        //else if element is greater we can go down in the column
        //Another analogy is that it is a binary search tree with top right and bottom left elements as nodes.

        int m = matrix.size();
        int n = matrix[0].size();
        int i=0, j=n-1;
        while(i<=m-1 && j>=0)
        {
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;
        }
        return false;
    }
}; 