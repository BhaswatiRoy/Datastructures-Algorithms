/*
A node is a terminal node if there are no outgoing edges. 
A node is a safe node if every possible path starting from that node leads to a terminal node.
You have to return an array containing all the safe nodes of the graph. The answers should be sorted in ascending order.
This can be done using simple cycle detection using DFS. Because for each node we can check if there is a cycle associated with the node.
If yes then that node is not a safe node.
*/

#include <bits/stdc++.h>
using namespace std;

bool cyclecheck(int node, vector<int> adj[], vector<int>&visited, vector<int>&pathvisited, vector<int>&check)
{
        visited[node]=1;
        pathvisited[node]=1;
        for(int j=0;j<adj[node].size();j++)
        {
            int adjnode=adj[node][j];
            //if cycle is found then they are unsafe nodes which stays 0 in check vector
            if(visited[adjnode]==0)
            {
                if(cyclecheck(adjnode,adj,visited,pathvisited,check)==true)
                {
                    return true;
                }
            }
            else
            {
                //node is visited & path visited
                if(pathvisited[adjnode]==1)
                {
                    return true;
                }
            }
        }
        //if no cycle was found for the current node then mark it as 1 in check
        check[node]=1;
        pathvisited[node]=0;
        return false;
}

//node which is a part of a cycle or connected to a cycle is unsafe node
//node which leads to a cycle is also unsafe node
//terminal nodes are safe nodes
vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
{
        vector<int>visited(V,0);
        vector<int>pathvisited(V,0);
        vector<int>check(V,0);
        vector<int>safenodes;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                cyclecheck(i,adj,visited,pathvisited,check);
            }
        }
        for(int k=0;k<V;k++)
        {
            if(check[k]==1)
            {
                safenodes.push_back(k);
            }
        }
        return safenodes;
}

//gfg driver code
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~" << "\n";
    }
}
