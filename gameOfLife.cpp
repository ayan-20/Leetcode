//Source : https://leetcode.com/problems/game-of-life/
//Author : Ayan Agrawal
//Date   : 25-06-2021

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {1,1,0,-1,-1,-1,0,1};//directions to access from a cell
        int dy[8] = {0,1,1,1,0,-1,-1,-1};//(dx,dy) denotes all 8 directions from a cell
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int count =0;
                for(int k=0; k<8; k++)
                {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x>=0 && x<m && y>=0 && y<n && (board[x][y]==1 || board[x][y]==2))//if board[x][y]==2 then also cell is alive 
                    {
                        count++;
                    }
                }
                if(board[i][j]==1)
                {
                    if(count<2 || count>3)
                    {
                        board[i][j]=2;//2 means live to dead as later we will do % with 2
                    }
                }
                else
                {
                    if(count==3)
                    {
                        board[i][j]=3;//3 means dead to alive as 3%2==1
                    }
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                board[i][j]%=2;
            }
        }
    }
};