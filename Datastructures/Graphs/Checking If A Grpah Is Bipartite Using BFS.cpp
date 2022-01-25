#include<bits/stdc++.h>
using namespace std;

//graphs with even/no cycle is a bipartite graph
bool bipartitebfs(int sourcenode,vector<int>adj[],vector<int>color)
{
	queue<int>q;
	//source node is starting node of bfs
	q.push(sourcenode);
	//color that node with 1st color i.e 0
	color[sourcenode]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it=adj[node].begin();it!=adj[node].end();it++)
		{
			//if the node is unvisited then it will be marked as -1
			if(color[*it]==-1)
			{
				//color that next node with exact opp color of the current node
				//if node=1 then adj node=1-0=1/ adj node=1-1=0
				color[*it]=1-color[node];
				q.push(*it);
			}
			//if color of adjacent node & current node is same then they the graph is not bipartite
			else if(color[*it]!=-1 && color[*it]==color[node])
			{
				return false;
			}
		}
	}
	return true;
}

bool checkbipartite(vector<int>adj[],int n)
{
	vector<int>color(n,-1);
	//iterating for all the nodes
	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
		    //if any of the portion of the graph returns false then whole tree is not bipartite
			if(bipartitebfs(i,adj,color)==false)
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

