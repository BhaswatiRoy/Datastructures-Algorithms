/*
Given a matrix with a startrow,startcol and a new color we have to keep on coloring the start point and all nearby points having same initial colors with new color.
We can only consider top,down,right,left in the adjacent points not diagonals
We have to then return the final matrix after doing everything.

TC - O(n*m), SC - O(n*m) - n = no of rows, m = no of cols
*/

void dfs(int i, int j, int newcolor, int initialcolor, vector<vector<int>>&image)
{
        //check if boundary constraints are reached or water is found then return 
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size())
        {
            return;
        }
        //check if the point has already been colored by new color or the point doesn't have the initial color
        if(image[i][j]==newcolor || image[i][j]!=initialcolor)
        {
            return;
        }
        //mark the current point with new color
        image[i][j]=newcolor;
        //perform dfs for all 4 directions of current point
        dfs(i-1,j,newcolor,initialcolor,image);
        dfs(i+1,j,newcolor,initialcolor,image);
        dfs(i,j-1,newcolor,initialcolor,image);
        dfs(i,j+1,newcolor,initialcolor,image);
        
}

void bfs(int i, int j, int newcolor, int initialcolor, vector<vector<int>>&image)
{
        queue<pair<int,int>>q;
        q.push({i,j});
        image[i][j]=newcolor;
        //neighbouring points are mainly {r-1,c},{r,c+1},{r+1,c},{r,c-1}
        vector<int>deltax={-1,0,+1,0};
        vector<int>deltay={0,+1,0,-1};
        while(!q.empty())
        {
            //finding row,col value of current node from queue
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            //traverse the neighbours of the given point (row,col) which is ith value of delatax & deltay vector
            for(int i=0;i<4;i++)
            {
                int newx=x+deltax[i];
                int newy=y+deltay[i];
                //checking valid (row,col) points and they should be equal to initialcolor too
                if(newx>=0 && newx<image.size() && newy>=0 && newy<image[0].size() && image[newx][newy]==initialcolor)
                {
                    q.push({newx,newy});
                    //set the valid nearby points to newcolor
                    image[newx][newy]=newcolor;
                }
            }
        }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) 
{
        int initialcolor=image[sr][sc];
        dfs(sr,sc,newcolor,initialcolor,image); / if(image[sr][sc]!=newColor) bfs(sr,sc,newColor,initialcolor,image);

        return image;
}
