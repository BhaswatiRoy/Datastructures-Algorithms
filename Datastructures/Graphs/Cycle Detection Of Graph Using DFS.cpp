#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int node,int parentnode,vector<int>adj[],vector<int>&visited)
{
	//mark the node as visited
	visited[node]=1;
	for(auto it=adj[node].begin();it!=adj[node].end();it++)
	{
		//check if the node is unvisited then we will recursively call the function to check for adjacent nodes
		if(visited[*it]==0)
		{
			//if any portion of recursive call of the function returns true then cycle is present 
			if(checkcycle(*it,node,adj,visited)==true)
			{
				return true;
			}
		}
		//if the next adjacent node is already visited and it is not parent node then cycle is present
		else if(visited[*it]==1 && *it!=parentnode)
		{
			return true;
		}
	}
	return false;
}

//function to check if any node faces a cycle i.e a visited node!=parent node then there is cycle in the graph
bool iscycle(int v,vector<int>adj[])
{
	vector<int>visited(v+1,0);
	for(int i=1;i<=v;i++)
	{
		//check if the node is unvisited then we will visit that node to do further checks
		if(visited[i]==0)
		{
			if(checkcycle(i,-1,adj,visited)==true)
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
		adj[v2].push_back(v1);
	}
	
	if(iscycle(v,adj)==true)
	{
		cout<<"Cycle Is Present!"<<endl;
	}
	else
	{
		cout<<"Cycle Is Absent"<<endl;
	}
}

