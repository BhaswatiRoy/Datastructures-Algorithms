#include<bits/stdc++.h>
using namespace std;

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

