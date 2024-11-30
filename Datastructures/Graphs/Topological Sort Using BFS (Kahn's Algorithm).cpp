#include<bits/stdc++.h>
using namespace std;

/*In Topo sort by DFS we don't need an in-degree vector 
But in Topological Sort by BFS we need to maintain an in-degree vector.
Push all the nodes with in-degree = 0 in the queue 
there is a guarantee of indegree = 0 nodes in a DAG
Now take them out of the queue one by one and reduce the in-degree of the adjacent nodes of them
Do this till the in-degree of those adjacent nodes becomes 0 and thus push them to the queue as well
*/

void toposort(int V, vector<vector<int>>&adj, vector<int>&indegree, vector<int>&kahns)
{
        queue<int>q;
        //push the nodes with in-degree 0 into the queue
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
		//reduce the indegree of the adjacent nodes
		//keep on doing till we get adjacent nodes with 0 indegree to push in queue
                indegree[adjnode]--;
                if(indegree[adjnode]==0)
                {
                    q.push(adjnode);
                }
            }
        }
}

vector<int> topologicalSort(vector<vector<int>>& adj) 
{
        int V=adj.size();
        vector<int>indegree(V,0);
        vector<int>kahns;
        for(int i=0;i<V;i++)
        {
            vector<int>adjnodes=adj[i];
            for(int j=0;j<adjnodes.size();j++)
            {
                indegree[adjnodes[j]]++;
            }
        }
        toposort(V,adj,indegree,kahns);
        return kahns;
}
