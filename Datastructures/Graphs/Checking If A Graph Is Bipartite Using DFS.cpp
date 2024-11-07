#include<bits/stdc++.h>
using namespace std;

/*
We will maintain a color vector which will initially has -1 representing no color. Then we will keep on coloring nodes in the opposite color of the parent node
Everytime in bfs call, there is a check that if the node's adjacent nodes are colored then do they have different colors than it if not then not a bipartite graph
*/

//graphs with even/no cycle is a bipartite graph
bool checkbipartite(int node, int lastcolor, vector<int>adj[], vector<int>&color)
{
        color[node]=lastcolor;
        for(int j=0;j<adj[node].size();j++)
        {
            int adjnode=adj[node][j];
            if(color[adjnode]==-1)
            {
                //adjnode color will be opp to node color
                int currcolor;
                if(lastcolor==0)
                {
                    currcolor=1;
                }
                else
                {
                    currcolor=0;
                }
                //check dfs for adj node as well
                if(checkbipartite(adjnode,currcolor,adj,color)==false)
                {
                    return false;
                }
            }
            else
            {
                if(color[adjnode]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
}

bool isBipartite(int V, vector<int>adj[])
{
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        //check only for noncolored start points in disconnected components
	        if(color[i]==-1)
	        {
	            if(checkbipartite(i,0,adj,color)==false)
	            {
	                return false;
	            }
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

