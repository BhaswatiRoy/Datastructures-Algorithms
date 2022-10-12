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

void bfstraversal(int row, int col, vector<vector<char>>& grid, vector<vector<int>>&visited)
{
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty())
        {
            //finding row,col value of current node from queue
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            //traverse the neighbours of the given point (row,col) which is -1 to +1 of that point
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    //calculating new row,col value using delrow,delcol from current node
                    int newrow=row+delrow;
                    int newcol=col+delcol;
                    //checking valid (row,col) points and they should be land + non visited as well
                    if((newrow>=0 && newrow<n) && (newcol>=0 && newcol<m) && grid[newrow][newcol]=='1' && !visited[newrow][newcol])
                    {
                        visited[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
}

int numIslands(vector<vector<char>>& grid) 
{
        int n=grid.size();
        int m=grid[0].size();
        //visited vector storing the (i,j) values that are visited
        vector<vector<int>>visited(n+1,vector<int>(m+1,0));
        int islandcount=0;
        //traverse through the grid and find islands
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //check if any land is present which is unvisited
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    islandcount++;
                    //then call dfs/bfs call and count all the adjacent points as 1 into 1 single island
                    //better to use dfs as bfs is not more optimal
                    dfstraversal(i,j,grid,visited) / dfstraversalbetter(i,j,grid) / bfstraversal
                }
            }
        }
        return islandcount;
}
