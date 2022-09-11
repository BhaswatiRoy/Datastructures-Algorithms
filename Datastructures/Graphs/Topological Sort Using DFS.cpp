#include<bits/stdc++.h>
using namespace std;

/*
In DFS we recursively reach to adjacent nodes and print them first then come to current node.
But in Topological Sort we store the current node 1st in stack then move to adjacent nodes. Thus we push the node whose dfs call is completed into the stack
*/

//dfs function with a bit modification
void findtopologicalsort(int sourcenode,vector<int>&visited,stack<int>&st,vector<int>adj[])
{
	//mark current node as visited
	visited[sourcenode]=1;
	for(auto it=adj[sourcenode].begin();it!=adj[sourcenode].end();it++)
	{
		if(visited[*it]==0)
		{
			findtopologicalsort(*it,visited,st,adj);
		}
	}
	//only difference with topological sort & normal dfs
	st.push(sourcenode);
}

void topologicalsort(int v,vector<int>adj[])
{
	//define a stack datastructure to store the topological sort format of nodes
	stack<int>st;
	vector<int>visited(v,0);
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
			findtopologicalsort(i,visited,st,adj);
		}
	}
	while(!st.empty())
	{
		//empty the stack in LIFO order to print
        cout<<st.top()<<" ";
        st.pop();
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
	}
	topologicalsort(v,adj);
}

