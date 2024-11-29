#include<bits/stdc++.h>
using namespace std;

/*
Topo sort: the linear ordering of vertices such that for u->v, u appears before v in the ordering
Topo sort is only valid for Directed Acyclic Graph (DAG) 
Because for undirected graphs 1 - 2, 1 has to come before 2 & 2 has to go before 1 which is practically impossible
For cycles also every node has to appear before its adjacent which is practically impossible

When we start with a node, we reach its adjacent nodes until we reach a point where it has no adjacent
We can only go to a node if it's not visited earlier
As we finish the call for a node then we push it into a stack
Then finally empty the stack and store elements to an array in LIFO format to get topo sort
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
	//as soon as the call finishes, push it to stack
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

