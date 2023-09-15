vector<vector<int>>allpaths;
vector<int>onepath;
void dfs(vector<int>adj[], int node, int destination)
{
        onepath.push_back(node);
        if(node==destination)
        {
            allpaths.push_back(onepath);
        }
        for(auto it:adj[node])
        {
            dfs(adj, it, destination);
        }
        onepath.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
{
        int v=graph.size();
        vector<int>adj[v];
        int source=0, destination=v-1;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        dfs(adj, source, destination);
        return allpaths;
}
