#include<bits/stdc++.h>
using namespace std;

/*
We will maintain a color vector which will initially has -1 representing no color. Then we will keep on coloring nodes in the opposite color of the parent node
Everytime in bfs call, there is a check that if the node's adjacent nodes are colored then do they have different colors than it if not then not a bipartite graph
*/

//graphs with even/no cycle is a bipartite graph
bool bipartitedfs(int sourcenode,vector<int>adj[],vector<int>color)
{
	//source node is starting node of bfs
	if(color[sourcenode]==-1)
	{
		//color that node with 1st color i.e 0
		color[sourcenode]=0;
	}
	for(auto it=adj[sourcenode].begin();it!=adj[sourcenode].end();it++)
	{
		//if the node is unvisited then it will be marked as -1
		if(color[*it]==-1)
		{
			//color that next node with exact opp color of the current node
			//if node=1 then adj node=1-0=1/ adj node=1-1=0
			color[*it]=1-color[sourcenode];
			//if any portion of graph traversal returns a false then the graph is not bipartite
			if(bipartitedfs(*it,adj,color)==false)
			{
				return false;
			}
		}
		//if color of adjacent node & current node is same then they the graph is not bipartite
		else if(color[*it]!=-1 && color[*it]==color[sourcenode])
		{
			return false;
		}
	}
	return true;
}

bool checkbipartite(vector<int>adj[],int v)
{
	vector<int>color(v,-1);
	//iterating for all the nodes
	for(int i=0;i<v;i++)
	{
		if(color[i]==-1)
		{
		    //if any of the portion of the graph returns false then whole tree is not bipartite
			if(bipartitedfs(i,adj,color)==false)
			{
				return false;
			}
		}
	}
	return true;
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
	
	if(checkbipartite(adj,v)==true)
	{
		cout<<"Bipartite Graph!"<<endl;
	}
	else
	{
		cout<<"Not Bipartite Graph"<<endl;
	}
}

