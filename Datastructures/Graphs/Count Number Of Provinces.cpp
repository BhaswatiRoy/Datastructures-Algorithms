/*
province is a set of nodes that are connected with eachother such that a path exists from each node to every other node in the province.
Now while doing BFS/DFS we visit all adjacent nodes of a particular node, so all visited nodes will become part of that province
Now the next unvisited node is part of a new province, so everytime we get an unvisited node we can count a new province
*/

//BFS - GFG Version 
[Problem](https://www.geeksforgeeks.org/problems/number-of-provinces/1)
void bfs(int node, vector<int>adjlist[], vector<int>&visited, queue<int>&q)
{
        visited[node]=1;
        q.push(node);
        while(!q.empty())
        {
            int currnode=q.front();
            q.pop();
            for(int j=0;j<adjlist[currnode].size();j++)
            {
                int adjnode=adjlist[currnode][j];
                if(visited[adjnode]==0)
                {
                    visited[adjnode]=1;
                    q.push(adjnode);
                }
            }
        }
}

int numProvinces(vector<vector<int>> adj, int V) 
{
        //convert adjacency matrix to list
        vector<int>adjlist[V];
        for(int k=0;k<V;k++)
        {
            for(int l=0;l<V;l++)
            {
                if(adj[k][l]==1 && l!=k)
                {
                    adjlist[k].push_back(l);
                }
            }
        }
        vector<int>visited(V,0);
        queue<int>q;
        int province_count=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                province_count++;
                bfs(i,adjlist,visited,q);
            }
        }
        return province_count;
}


//DFS - LC version
//TC = O(V), SC = O(V)
void dfstraversal(int node, vector<int>adjls[], vector<int>&visited)
    {
        visited[node]=1;
        for(auto it:adjls[node])
        {
            if(visited[it]==0)
            {
                dfstraversal(it,adjls,visited);
            }
        }
    }
    
int findCircleNum(vector<int>adjls[], int V) 
    {
        vector<int>visited(V+1,0);
        int provincecount=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                provincecount++;
                dfstraversal(i,adjls,visited);
            }
        }
        return provincecount;
    }
