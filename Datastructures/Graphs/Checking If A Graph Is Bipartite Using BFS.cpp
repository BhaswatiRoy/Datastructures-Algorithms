#include<bits/stdc++.h>
using namespace std;

/*
We will maintain a color vector which will initially has -1 representing no color. Then we will keep on coloring nodes in the opposite color of the parent node
Everytime in bfs call, there is a check that if the node's adjacent nodes are colored then do they have different colors than it if not then not a bipartite graph
*/

//graphs with even/no cycle is a bipartite graph
//test cases failing largely like 1/825 means connected component problem
    bool checkbipartite(int start, vector<int>adj[], vector<int>&color)
    {
        queue<int>q;
        q.push(start);
        while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        for(int i=0;i<adj[node].size();i++)
	        {
	            int adjnode=adj[node][i];
	            //uncolored node then color it with opp color from parent
	            if(color[adjnode]==-1)
	            {
	                if(color[node]==0)
	                {
	                    color[adjnode]=1;
	                }
	                else
	                {
	                    color[adjnode]=0;
	                }
	                q.push(adjnode);
	            }
	            //color node then check if color is diff from parent
	            else
	            {
	                if(color[adjnode]==color[node])
	                {
	                    return false;
	                }
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    //-1 = no color, 0/1 = colors
	    vector<int>color(V,-1);
	    color[0]=0;
	    for(int i=0;i<V;i++)
	    {
	        if(checkbipartite(i,adj,color)==false)
	        {
	            return false;
	        }
	    }
	    return true;
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
	
	if(checkbipartite(adj,v)==true)
	{
		cout<<"Bipartite Graph!"<<endl;
	}
	else
	{
		cout<<"Not Bipartite Graph"<<endl;
	}
}

