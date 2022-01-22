#include<bits/stdc++.h>
using namespace std;

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
	
	cout<<"Adjacency List After Adding Nodes:"<<endl;
	for(int p=1;p<=v;p++)
	{
		cout<<"For Vertex "<<p;
		for(auto q:adj[p])
		{
			cout<<"->"<<q;
		}
		cout<<endl;
	}
	cout<<endl;
}
