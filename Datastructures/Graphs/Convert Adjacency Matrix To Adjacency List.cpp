//sometimes due to small inputs taken, adjacency matrices are given and we need to convert them to adjacency lists to work

//adjacency matrix
vector<vector<int>>adj

//adjacency list
vector<int>adjls[V];
for(int i=0;i<V;i++)
{
     for(int j=0;j<V;j++)
     {
           //i!=j is done to avoid self nodes
           if(adj[i][j]==1 && i!=j)
           {
                adjls[i].push_back(j);
                adjls[j].push_back(i);
           }
     }
}
