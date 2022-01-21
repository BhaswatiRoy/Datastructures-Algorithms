#include <bits/stdc++.h>
using namespace std;

int main() 
{
	//v=no of vertices, e=no of edges
	int v,e;
	cout<<"Enter number of vertices:";
	cin>>v;
	cout<<"Enter number of edges:";
	cin>>e;
	
	//declare the adjacency matrix of v x e size
	int adj[v+1][e+1]={};
	
	cout<<"Adjacency Matrix before filling the edges:"<<endl;
	for(int j=0;j<v;j++)
	{
		for(int k=0;k<e;k++)
		{
			cout<<adj[j][k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//take edges as input
	for(int i=1;i<=e;i++)
	{
		//edge exists between v1 & v2 vertices
		int v1,v2;
		cout<<"Enter the vertices between whom edges exist:";
		cin>>v1>>v2;
		//for undirected graph edge will exist between v1 & v2 as well as v1 & v2
		adj[v1][v2]=1;
		adj[v2][v1]=1;
	}
	cout<<endl;
	
	cout<<"Adjacency Matrix after filling the edges:"<<endl;
    for(int j=1;j<=v;j++)
	{
		for(int k=1;k<=e;k++)
		{
			cout<<adj[j][k]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

