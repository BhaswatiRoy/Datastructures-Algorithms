#include<bits/stdc++.h>
using namespace std;

//function to do topoloigical sort
void findtopologicalsort(int node,vector<int>&visited,stack<int>&st,vector<pair<int,int>>adj[])
{
	visited[node]=1;
	for(auto it=adj[node].begin();it!=adj[node].end();it++)
	{
		if(visited[(*it).first]==0)
		{
			findtopologicalsort((*it).first,visited,st,adj);
		}
	}
	//as soon as recursion call of any node ends it gets pushed to stack
	st.push(node);
} 

void shortestpath(int v,vector<pair<int,int>>adj[],int sourcenode)
{
	vector<int>visited(v+1,0);
	stack<int>st;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==0)
		{
			findtopologicalsort(i,visited,st,adj);
		}
	}
	//all elements of the distance vector is marked as INT_MAX 
	vector<int>distance(v+1,INT_MAX);
	//distance of sourcenode from sourcenode is always 0
	//distance node at 0 index is marked as 0 as our graph starts from node value 1 so we might get garbage value
	distance[0]=distance[sourcenode]=0;
	
	while(!st.empty())
	{
		int node=st.top();
		st.pop();
		//if that node is visited previosuly so it will be not INT_MAX and now we can traverse for it's adjacent nodes
		if(distance[node]!=INT_MAX)
		{
			for(auto it=adj[node].begin();it!=adj[node].end();it++)
			{
				//it.first=adjacent node value, it.second=current to adjacent node edge weight
				if(distance[node]+(*it).second<distance[(*it).first])
				{
					//thus distance till current node+edge weight is less than distance of adjacent node then it will be replaced
					distance[(*it).first]=distance[node]+(*it).second;
				}
			}
		}
	}
	for(int i=1;i<=v;i++)
	{
		if(distance[i]==INT_MAX)
		{
			cout<<"Infinity!!"<<endl;
		}
		else
		{
			cout<<distance[i]<<" ";
		}
	}
	cout<<endl;
}

int main()
{
	//v=no of vertices, e=no of edges
	int v,e,wt;
	cout<<"Enter number of vertices:";
	cin>>v;
	cout<<"Enter number of edges:";
	cin>>e;
	
	vector<pair<int,int>>adj[v+1];
	
	//take edges as input
	for(int i=1;i<=e;i++)
	{
		int v1,v2;
		cout<<"Enter The Vertices Between Which Edge Exist:";
		cin>>v1>>v2;
		cout<<"Enter The Weight Of That Edge:";
		cin>>wt;
		
		//for directed graph edge will exist between v1 & v2 but not v1 & v2
		//storing pair of adjacent node and weight of a node
		adj[v1].push_back({v2,wt});
	}
	int sourcenode;
	cout<<"Enter the source node:";
	cin>>sourcenode;
	shortestpath(v,adj,sourcenode);
}

