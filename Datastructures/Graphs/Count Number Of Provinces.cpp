/*
province is a set of nodes that are connected with eachother such that a path exists from each node to every other node in the province.
Now while doing BFS/DFS we visit all adjacent nodes of a particular node, so all visited nodes will become part of that province
Now the next unvisited node is part of a new province, so everytime we get an unvisited node we can count a new province
*/

//TC = O(V), SC = O(V)
void dfstraversal(int node, vector<int>adjls[], vector<int>&visited)
    {
        visited[node]=1;
        for(auto it:adjls[node])
        {
            if(visited[it]==0)
            {
                dfstraversal(it,adjls,visited);
            }
        }
    }
    
int findCircleNum(vector<int>adjls[], int V) 
    {
        vector<int>visited(V+1,0);
        int provincecount=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                provincecount++;
                dfstraversal(i,adjls,visited);
            }
        }
        return provincecount;
    }
