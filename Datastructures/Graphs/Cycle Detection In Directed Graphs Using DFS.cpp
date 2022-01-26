#include<bits/stdc++.h>
using namespace std;

//for directed graphs we need to maintain 2 vectors and also direction matters for cycle
bool checkcycle(int sourcenode,vector<int>adj[],vector<int>visited,vector<int>dfsvisited)
{
	//marking that node in both vectors as 1
	visited[sourcenode]=1;
	dfsvisited[sourcenode]=1;
	for(auto it=adj[sourcenode].begin();it!=adj[sourcenode].end();it++)
	{
		//if the node is unvisited
		if(visited[*it]==0)
		{
			if(checkcycle(*it,adj,visited,dfsvisited))
			{
				return true;
			}
		}
		//if the node is visited & also visited in the same cycle 
		else if(visited[*it]==1 && dfsvisited[*it]==1)
		{
			return true;
		}
	}
	//if we did not find a cycle we will make that node as 0 in dfsvisited vector and return false in end
	dfsvisited[sourcenode]=0;
	return false;
}

bool iscycle(int v,vector<int>adj[])
{
	vector<int>visited(v,0);
	vector<int>dfsvisited(v,0);
	for(int i=0;i<v;i++)
	{
		if(visited[i]==0)
		{
			if(checkcycle(i,adj,visited,dfsvisited))
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
		//adj[v2].push_back(v1);
	}
	
	if(iscycle(v,adj)==true)
	{
		cout<<"Cycle Present!"<<endl;
	}
	else
	{
		cout<<"Cycle Absent"<<endl;
	}
}

