#include<bits/stdc++.h>
using namespace std;

/*
Cycle Detection Using BFS -
We check if any node is not parent node but is still visited then there must be a cycle there which is why it is visited
*/

bool checkcycle(int start, vector<int>&visited, vector<int>adj[])
    {
        visited[start]=1;
        queue<pair<int,int>>q;
        q.push({start,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int j=0;j<adj[node].size();j++)
            {
                int neighbor=adj[node][j];
                if(visited[neighbor]==0)
                {
                    q.push({neighbor,node});
                    visited[neighbor]=1;
                }
                else if(neighbor!=parent)
                {
                    return true;
                }
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
                if(checkcycle(i,visited,adj)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

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

