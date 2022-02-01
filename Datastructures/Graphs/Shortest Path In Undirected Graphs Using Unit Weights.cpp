#include<bits/stdc++.h>
using namespace std;

//simple bfs with a bit modification by using a separate extra vector which is distance vector
void shortestpath(int v,vector<int>adj[],int sourcenode)
{
	//define all nodes of the distance vector as the maximum value
	vector<int>distance(v+1,INT_MAX);
	queue<int>q;
	
	//distance of sourcenode from sourcenode is always 0
	//distance node at 0 index is marked as 0 as our graph starts from node value 1 so we might get garbage value
	distance[sourcenode]=distance[0]=0;
	q.push(sourcenode);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		
		//traverse for all adjacent nodes
		for(auto it=adj[node].begin();it!=adj[node].end();it++)
		{
			//got shorter path to reach to that node from source node
			//suppose node 2 has adjacent node 3 so node=2 and *it=3
			//also +1 is for going to the next adj node from current node as all weights are 1
			if(distance[node]+1<distance[*it])
			{
				//then replace that value in distance vector
				distance[*it]=distance[node]+1;
				q.push(*it);
			}
		}
	}
	for(int i=1;i<=v;i++)
	{
		cout<<distance[i]<<" ";
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
		
		//for directed graph edge will exist between v1 & v2 but not v1 & v2
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int sourcenode;
	cout<<"Enter the source node:";
	cin>>sourcenode;
	shortestpath(v,adj,sourcenode);
}

