#include<bits/stdc++.h>
using namespace std;

/*
BFS Traversal -
We check adjacency list and push the node into the queue and mark it as visited in visited vector then move to it's adjacent elements.
After that we will push the adjacent nodes of that node and finally pop that node out. We only push any node into queue if it is not visited previously.
TC is O(V+E), SC is O(V+E)
*/

//adjancency list is vector of vectors
void bfstraversal(int v,vector<int>adj[])
{
	vector<int>bfs;
	//vector of size v+1 and all elements initially as 0
	vector<int>visited(v+1,0);
	queue<int>q;
	
	//the for loop is for traversing nodes for disjoint components of graph
	for(int i=1;i<=v;i++)
	{
		//if node is not visited
		if(visited[i]==0)
		{
			//then push it in queue and mark it as visited
			q.push(i);
			visited[i]=1;
			//traverse the adjacent nodes of that node untill all are visited
			while(!q.empty())
			{
				int node=q.front();
				q.pop();
				bfs.push_back(node);
				//traverse the adjacency list and check all 
				for(int i=0;i<adj[node].size();i++)
            			{
                			int adjnode=adj[node][i];
                			if(visited[adjnode]==0)
               		 		{
                    				q.push(adjnode);
                    				visited[adjnode]=1;
                			}
                    
            			}
				//another way - old way which worked always
				// for(auto it=adj[node].begin();it!=adj[node].end();it++)
				// {
				// 	if(visited[*it]==0)
				// 	{
				// 		q.push(*it);
				// 		visited[*it]=1;
				// 	}
				// }
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

