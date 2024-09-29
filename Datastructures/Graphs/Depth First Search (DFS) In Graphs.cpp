#include<bits/stdc++.h>
using namespace std;

/*
DFS Traversal -
We check the adjacency list and call a recursive dfs call for all adjacent nodes of that node which are unvisited.
The nodes which are visited during recursive dfs call must be marked as visited in the visited vector
TC is O(V+E), SC is O(V+E)
*/

//connected components
void dfsrecursion(int node, vector<int>adj[], vector<int>&visited, vector<int>&dfs)
{
        visited[node]=1;
        dfs.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            int adjnode=adj[node][i];
            if(visited[adjnode]==0)
            {
                dfsrecursion(adj[node][i],adj,visited,dfs);
            }
        }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) 
{
        vector<int>visited(V,0);
        visited[0]=1;
        vector<int>dfs;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                dfsrecursion(i,adj,visited,dfs);
            }
        }
        return dfs;
}

//non connected components
void dfspath(int node,vector<int>&visited,vector<int>adj[],vector<int>&dfs)
{
	dfs.push_back(node);
	visited[node]=1;
	cout<<node<<" ";
	for(auto it=adj[node].begin();it!=adj[node].end();it++)
	{
		if(visited[*it]==0)
		{
			dfspath(*it,visited,adj,dfs);
		}
	}
}

void dfstraversal(int v,vector<int>adj[])
{
	vector<int>dfs;
	//vector of size v+1 and all elements 0 and as we traverse we will visit nodes and mark them as 1
	vector<int>visited(v+1,0);
	for(int i=1;i<=v;i++)
	{
		//if the node is not visited
		if(visited[i]==0)
		{
			dfspath(i,visited,adj,dfs);
		}
	}
}

int main()
{
	//v=no of vertices, e=no of edges
	int v,e;
	cout<<"Enter number of vertices:";
	cin>>v;
	cout<<"Enter number of edges:";
	cin>>e;
	
	vector<int>adj[v+1];
	
	//take edges as input
	for(int i=1;i<=e;i++)
	{
		int v1,v2;
		cout<<"Enter The Vertices Between Which Edge Exist:";
		cin>>v1>>v2;
		
		//for undirected graph edge will exist between v1 & v2 as well as v1 & v2
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	dfstraversal(v,adj);
}

