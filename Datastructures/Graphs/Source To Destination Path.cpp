bool sol=false;
//simple dfs call from start node
void dfs(int n, vector<int>adj[], vector<int>&visited, int node, int destination)
{
        //if we reach destination while dfs then return
        if(node==destination)
        {
            sol=true;
            return;
        }
        //otherwise visit all adjacent nodes and call dfs for them
        //continues until all nodes are traversed or we get destination
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                dfs(n, adj, visited, it, destination);
            }
        }
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
{
        vector<int>adj[n+1];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n+1, 0);
        dfs(n, adj, visited, source, destination);

        return sol;
}
