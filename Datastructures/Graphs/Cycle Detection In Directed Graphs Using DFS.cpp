#include<bits/stdc++.h>
using namespace std;

/*
if we simply use logic of an undirected graph then it will give wrong ans for directed graphs so instead of that we use 2 vectors for marking visit.
One is the visited vector another is dfs visited vector. The dfs visited vector keeps track if the node was visited in the current dfs recursion call or not.
Whenever the recursion call of one node ends then all the nodes under it will be marked as unvisited again in the dfs visited vector
Now if a node is marked as 1 in both visited and dfs visited then it indicates a cycle, as it has been visited in current dfs call
*/

/*
3 -> 4 -------
|            |   
-> 7 -> 5 <---
Normal DFS will say it's a cycle but it's not. Node has to be revisited for the same path. 
So we maintain a visited & a path visited array
*/

bool checkcycle(int node, vector<vector<int>>&adj, vector<int>&visited, vector<int>&pathvisited)
{
        visited[node]=1;
        pathvisited[node]=1;
        for(int j=0;j<adj[node].size();j++)
        {
            int adjnode=adj[node][j];
            //if adjnode is not visited run a dfs call on it
            if(visited[adjnode]==0)
            {
                if(checkcycle(adjnode,adj,visited,pathvisited)==true)
                {
                    return true;
                }
            }
            //but if it is visited and also visited in current path then cycle
            else
            {
                if(pathvisited[adjnode]==1)
                {
                    return true;
                }
            }
        }
        pathvisited[node]=0;
        return false;
}

bool isCyclic(int V, vector<vector<int>> adj) 
{
        //pathvisited to check if the node is visited in current path
        vector<int>visited(V,0);
        vector<int>pathvisited(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(checkcycle(i, adj, visited, pathvisited)==true)
                {
                    return true;
                }
            }
        }
        return false;
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
		//adj[v2].push_back(v1);
	}
	
	if(iscycle(v,adj)==true)
	{
		cout<<"Cycle Present!"<<endl;
	}
	else
	{
		cout<<"Cycle Absent"<<endl;
	}
}

