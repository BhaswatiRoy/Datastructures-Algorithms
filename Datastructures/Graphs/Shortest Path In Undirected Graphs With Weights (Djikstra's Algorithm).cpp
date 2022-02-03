#include<bits/stdc++.h>
using namespace std;

void dijkstra(int v,vector<pair<int,int>>adj,int sourcenode)
{
	//in priority queue we store in {shortest distance, node value}
	//made of min heap so smallest first value is stored on top of queue
	priority_queue<pair<int,int>>pq;
	//vector<pair<int,int>>;
	vector<int>distance(v+1,INT_MAX);
	
	//distance of sourcenode to itself is always 0
	distance[sourcenode]=0;
	pq.push({0,sourcenode});
	
	while(!pq.empty())
	{
		int dist=pq.top().first;
		int node=pq.top().second;
		pq.pop();
		
		vector<pair<int,int>>::iterator it;
		for(auto it:adj[node])
		{
			//when we store in adj list we store in {vertex, weight} format
			int nextnode=it.first;
			int nextnodedist=it.second;
			//if distance to travel to next node through this node is shorter than stored value
			if(distance[node]+nextnodedist<distance[nextnode])
			{
				//then store in distance vector
				distance[nextnode]=distance[node]+nextnodedist;
				//also push that value to queue
				pq.push({distance[nextnode],next});
			 } 
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<distance[i]<<" ";
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
		adj[v2].push_back({v1,wt});
	}
	int sourcenode;
	cout<<"Enter the source node:";
	cin>>sourcenode;
	shortestpath(v,adj,sourcenode);
}

