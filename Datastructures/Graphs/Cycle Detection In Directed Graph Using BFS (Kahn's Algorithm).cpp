/*
We will try to implement Kahn's Algorithm in a directed graph and try to produce topo sort
If its a DAG then we will get topo sort for all n nodes
But if its a directed graph with a cycle then we will get a topo sort with < n nodes

So if we get topo sort of n vectors then there is no cycle so return false
else true
*/

void toposort(int V, vector<vector<int>>&adj, vector<int>&indegree, vector<int>&kahns)
{
        for(int i=0;i<V;i++)
        {
            vector<int>adjnodes=adj[i];
            for(int j=0;j<adjnodes.size();j++)
            {
                indegree[adjnodes[j]]++;
            }
        }
        queue<int>q;
        for(int k=0;k<V;k++)
        {
            if(indegree[k]==0)
            {
                q.push(k);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            kahns.push_back(node);
            for(int l=0;l<adj[node].size();l++)
            {
                int adjnode=adj[node][l];
                indegree[adjnode]--;
                if(indegree[adjnode]==0)
                {
                    q.push(adjnode);
                }
            }
        }
}

bool isCyclic(int V, vector<vector<int>> adj) 
{
        vector<int>indegree(V,0);
        vector<int>kahns;
        toposort(V,adj,indegree,kahns);
        //no cycle if topo sort has all v nodes
        if(kahns.size()==V)
        {
            return false;
        }
        return true;
}
