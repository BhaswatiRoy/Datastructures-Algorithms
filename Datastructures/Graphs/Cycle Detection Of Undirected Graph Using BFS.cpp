#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int s,int v,vector<int>adj[],vector<int>&visited)
{
	//create queue for storing pair of <node,parent node>
	//storing parent node will help us verify if 
	queue<pair<int,int>>q;
	//visited node is marked as 1
	visited[s]=1;
	//initially parent node of the visited node is none so is marked as -1
	q.push({s,-1});
	
	while(!q.empty())
	{
		//store value of current & parent node
		int node=q.front().first;
		int parentnode=q.front().second;
		q.pop();
		//traverse &check for all the adjacent nodes of the current node
		for(auto it=adj[node].begin();it!=adj[node].end();it++)
		{
			if(visited[*it]==0)
			{
				visited[*it]=1;
				q.push({*it,node});
			}
			else if(visited[*it]==1 && parentnode!=*it)
			{
				return true;
			}
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
		if(visited[i]==0)
		{
			if(checkcycle(i,v,adj,visited)==true)
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

