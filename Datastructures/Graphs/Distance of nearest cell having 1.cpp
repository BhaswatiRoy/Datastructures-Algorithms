/*
Question: https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
0 0 0
0 1 0
1 0 1
for each 0's find the nearest 1's in 4 directions using BFS.
Now we could have done BFS from each 0 but it will give TLE.
Another way is to do multi-start BFS and take each 1's as a starting point and count the distance to the nearest 0's.
Distance from each 1 to 0 is the same as from 0 to 1. 
Check Striver video for better clarification
*/

vector<vector<int>> nearest(vector<vector<int>>& grid) 
{
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,-1,0,1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            visited[row][col]=1;
            distance[row][col]=time;
            for(int it=0;it<4;it++)
            {
                int newrow=row+delrow[it];
                int newcol=col+delcol[it];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m)
                {
                    if(visited[newrow][newcol]==0)
                    {
                        q.push({{newrow,newcol},time+1});
                        distance[newrow][newcol]=time;
                        visited[newrow][newcol]=1;
                    }
                }
            }
        }
        return distance;
}
