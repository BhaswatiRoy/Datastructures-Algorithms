/*
Island is a set of lands connected together surrounded by water. Thus for every connected 1's in matrix we check for all nearby 1's and count them as 1 island
Then check for the next unvisited node which is 1 so that must be part of some new island, so everytime we get an unvisited node we can count a new island.

TC - O(n^2), SC - O(n^2)
*/

//used the visited vector to keep track of visited nodes
void dfstraversal(int i, int j, vector<vector<char>>&grid,vector<vector<int>>&visited)
{
        //check if boundary constraints are reached or water is found then return 
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        {
            return;
        }
        //check if the point is already visited previously using visited vector
        if(visited[i][j]==1 || grid[i][j]=='0')
        {
            return;
        }
        //mark the current point as visited in the visited vector
        visited[i][j]=1;
        dfstraversal(i,j+1,grid,visited);
        dfstraversal(i,j-1,grid,visited);
        dfstraversal(i+1,j,grid,visited);
        dfstraversal(i-1,j,grid,visited);
 }

//no use of visited vector to keep track of visited nodes, instead made changes in actual grid vector
void dfstraversalbetter(int i, int j, vector<vector<char>>&grid)
{
        //check if boundary constraints are reached or water is found then return 
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        {
            return;
        }
        //check if the point is already visited previously
        if(grid[i][j]=='2' || grid[i][j]=='0')
        {
            return;
        }
        //mark the current point as visited by making it 2 instead of 1/0
        grid[i][j]='2';
        dfstraversalbetter(i,j+1,grid);
        dfstraversalbetter(i,j-1,grid);
        dfstraversalbetter(i+1,j,grid);
        dfstraversalbetter(i-1,j,grid);
}

//bfs traversal with diagonals not considered as neighbors - LC problem - https://leetcode.com/problems/number-of-islands/description/
void bfstraversal(int i, int j, int n, int m, vector<vector<char>>&grid, vector<vector<int>>&visited)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            //diagonal nodes not allowed so we cant use nested loops from -1 to 1 each
            //hence store in delrows and delcols so that we get 4 combinations for top,bottom,left,right
            vector<int>delrows={-1,0,1,0};
            vector<int>delcols={0,1,0,-1};
            for(int it=0;it<4;it++)
            {
                int neighborrow=row+delrows[it];
                int neighborcol=col+delcols[it];
                if((neighborrow>=0 && neighborrow<n) && (neighborcol>=0 && neighborcol<m) && grid[neighborrow][neighborcol]=='1' && !visited[neighborrow][neighborcol])
                {
                    q.push({neighborrow,neighborcol});
                    visited[neighborrow][neighborcol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                    count++;
                    bfstraversal(i,j,n,m,grid,visited);
                }
            }
        }
        return count;
    }
