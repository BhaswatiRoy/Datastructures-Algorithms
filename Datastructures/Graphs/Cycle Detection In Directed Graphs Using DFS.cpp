#include<bits/stdc++.h>
using namespace std;

/*
if we simply use logic of an undirected graph then it will give wrong ans for directed graphs so instead of that we use 2 vectors for marking visit.
One is the visited vector another is dfs visited vector. The dfs visited vector keeps track if the node was visited in the current dfs recursion call or not.
Whenever the recursion call of one node ends then all the nodes under it will be marked as unvisited again in the dfs visited vector
Now if a node is marked as 1 in both visited and dfs visited then it indicates a cycle, as it has been visited in current dfs call
*/

/*
3 -> 4 -------
|            |   
-> 7 -> 5 <---
Normal DFS will say it's a cycle but it's not. Node has to be revisited for the same path. 
So we maintain a visited & a path visited array
*/

bool dfscyclecheck(int sourcenode, vector<int>adj[],vector<int>&visited,vector<int>&dfsvisited)
{
       //marking that node in both vectors as 1
        visited[sourcenode]=1;
        dfsvisited[sourcenode]=1;
        for(auto it=adj[sourcenode].begin();it!=adj[sourcenode].end();it++)
        {
            //if the node is unvisited
            if(visited[*it]==0)
            {
                //recursively call the function and check for all nodes
                if(dfscyclecheck(*it,adj,visited,dfsvisited)==true)
                {
                    return true;
                }
            }
            //if the node was visited(visited[*it]=1) and visited in same directed traversal(dfsvisited[*it]=1)
            else if(visited[*it]==1 && dfsvisited[*it]==1)
            {
                return true;
            }
        }
        //if we did not find a cycle in this traversal then we will make that node as 0 in dfsvisited vector 
	dfsvisited[sourcenode]=0;
	return false;
}
bool isCyclic(int V, vector<int> adj[]) 
{
        //marks all nodes that are visited as 1
        vector<int>visited(V+1,0);
        //marks nodes that are visited as 1 and when recursion call is returned while going back it again marks as 0
        //this will keep track if the node was visited in directed traversal
        vector<int>dfsvisited(V+1,0);
        for(int i=0;i<V;i++)
        {
            //check if the node is unvisited then we will visit that node to do further checks
            if(visited[i]==0)
            {
		//if there is cycle for any node then there is cycle in entire graph
                if(dfscyclecheck(i,adj,visited,dfsvisited)==true)
                {
                    return true;
                }
            }
        }
        //if no node could return true then there is no cycle in entire graph
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

