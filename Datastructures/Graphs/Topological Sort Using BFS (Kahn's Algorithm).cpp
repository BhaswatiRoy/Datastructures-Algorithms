#include<bits/stdc++.h>
using namespace std;

/*In BFS we don't need an indegree vector 
But in Topological Sort by BFS we need to maintain an indegree vector.
We will check nodes and reduce the indegree of adjacent nodes by 1 to finally make as 0
Also everytime we get a node with indegree of 0 we will push it to queue and later print accordingly
*/

//bfs function with a bit modification i.e using an indegree vector
void topologicalsort(int v,vector<int>adj[])
{
	//define a queue to store the topological sort format of nodes i.e nodes which has indegree marked as 0
	queue<int>q;
	//define the indegree vector
	vector<int>indegree(v,0);
	for(int i=0;i<v;i++)
	{
		//for every adjacent nodes of any node there is an indegree of that node that's why edge exists 
		for(auto it=adj[i].begin();it!=adj[i].end();it++)
		{
			//storing indegree of each node in the indegree vector
			indegree[*it]++;
		}
	}
	//now adding all nodes to the queue which has indegree as 0 
	for(int i=1;i<= v;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	//define the topological sort vector to store the format
	vector<int>topo;
	while(!q.empty())
	{
		int sourcenode=q.front();
		q.pop();
		//push that node to queue
		topo.push_back(sourcenode);
		//the iterate through all the adjacent nodes of that node and indegree of those adjacent nodes are reduced by 1
		for(auto it=adj[sourcenode].begin();it!=adj[sourcenode].end();it++)
		{
			indegree[*it]--;
			if(indegree[*it]==0)
			{
				q.push(*it);
			}
		}
	}
	//finally print the elements of the vector 
	for(int i=0;i<topo.size();i++)
	{
		cout<<topo[i]<<" ";
	}
	cout<<endl;
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

