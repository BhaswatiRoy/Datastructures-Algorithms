#include<bits/stdc++.h>
using namespace std;

//adjancency list is vector of vectors
void bfstraversal(int v,vector<int>adj[])
{
	vector<int>bfs;
	//vector of size v+1 and all elements as 0
	vector<int>visited(v+1,0);
	queue<int>q;
	
	for(int i=1;i<=v;i++)
	{
		//if node is not visited
		if(visited[i]==0)
		{
			q.push(i);
			visited[i]=1;
			while(!q.empty())
			{
				int node=q.front();
				q.pop();
				bfs.push_back(node);
				for(auto it=adj[node].begin();it!=adj[node].end();it++)
				{
					if(visited[*it]==0)
					{
						q.push(*it);
						visited[*it]=1;
					}
				}
			}
		}
	}
	for(int j=0;j<bfs.size();j++)
	{
		cout<<bfs[j]<<" ";
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
		
		//for undirected graph edge will exist between v1 & v2 as well as v1 & v2
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	bfstraversal(v,adj);
}

