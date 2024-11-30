#include<bits/stdc++.h>
using namespace std;

/*
Topo sort: the linear ordering of vertices such that for u->v, u appears before v in the ordering
Topo sort is only valid for Directed Acyclic Graph (DAG) 
Because for undirected graphs 1 - 2, 1 has to come before 2 & 2 has to go before 1 which is practically impossible
For cycles also every node has to appear before its adjacent which is almost impossible

When we start with a node, we reach its adjacent nodes until we reach a point where it has no adjacent
We can only go to a node if it's not visited earlier
As we finish the call for a node then we push it into a stack
Then finally empty the stack and store elements to an array in LIFO format to get topo sort
*/

void toposort(int node, vector<vector<int>>&adj, vector<int>&visited, stack<int>&st)
{
        visited[node]=1;
        for(int j=0;j<adj[node].size();j++)
        {
            int adjnode=adj[node][j];
	    //keep on doing dfs call till we reach the end of a path 
	    //end of path does not have any adjacents
            if(visited[adjnode]==0)
            {
                toposort(adjnode,adj,visited,st);
            }
        }
	//once the dfs call of a node is done then we push it to stack
	//so the node at end of the path will be pushed
        st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& adj) 
{
        int V=adj.size();
        vector<int>visited(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                toposort(i,adj,visited,st);
            }
        }
        vector<int>and;
	//in end empty the stack in LIFO format to get the topo sort order
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
}
