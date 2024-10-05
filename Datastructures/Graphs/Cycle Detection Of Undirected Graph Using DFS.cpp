#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int node, int parent, vector<int>adj[],vector<int>&visited)
{
        visited[node]=1;
        for(int j=0;j<adj[node].size();j++)
        {
            int neighbor=adj[node][j];
            if(visited[neighbor]==0)
            {
                if(checkcycle(neighbor,node,adj,visited)==true)
                {
                    return true;
                }
            }
            else if(neighbor!=parent && visited[neighbor]==1)
            {
                return true;
            }
        }
        return false;
}

bool isCycle(int V, vector<int> adj[]) 
{
        vector<int>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(checkcycle(i,-1,adj,visited)==true)
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
		adj[v2].push_back(v1);
	}
	
	if(iscycle(v,adj)==true)
	{
		cout<<"Cycle Is Present!"<<endl;
	}
	else
	{
		cout<<"Cycle Is Absent"<<endl;
	}
}

