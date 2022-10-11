/*
Given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water. We need perimeter of the land.
By looking at the figure we can see that for grids at boundary of matrix we can count 1 in boundary side for perimeter
And for others if any direction of grid has water we can again count 1 for that.

TC - O(n^2), SC - O(1)
*/

//check if the current row,col is outside the boundary of matrix or not
bool checkboundary(int row, int col, int m, int n)
{
        if (row==-1 || row==n || col==-1 || col==m)
        {
            return true;
        }
        return false;
}
int islandPerimeter(vector<vector<int>>& grid) 
{
        int n=grid.size();
        int m=grid[0].size();
        int perimeter=0;
        
        //direction arrays created to check all 4 directions of a grid
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    for(int k=0;k<4;k++)
                    {
                        int newrow=(i+delrow[k]);
                        int newcol=(j+delcol[k]);
                        //if newrow,newcol is going outside matrix boundary then i,j is at boundary
                        //thus for every boundary we will do +1
                        if(checkboundary(newrow,newcol,m,n))
                        {
                            perimeter++;
                        }
                        //and if any side of the current grid is water the consider +1 
                        else if(grid[newrow][newcol]==0)
                        {
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
}
