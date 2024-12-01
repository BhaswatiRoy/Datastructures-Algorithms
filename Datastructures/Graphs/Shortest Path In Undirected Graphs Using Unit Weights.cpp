/*
1. Create a "distance" vector for all N nodes and set them to INT_MAX
2. Store {node, distance from start} pairs in the queue
3. {start,0} will be pushed first as the distance from start to itself is always 0
4. Then we will check adj elements from the queue and do +1 with each 
5. Then we will compare with the "distance" vector if we get a better distance
6. If we get a better distance, store that in the "distance" vector and push the {node, distance} to the queue

TC: O(N + M) -> each edge & node will be processed once
SC: O(N + M) -> store the graph in adjacency list
*/


void shortestdist(int N, int src, vector<vector<int>>&adj, vector<int>&distance)
{
        //queue to store {node, distance of node from source}
        queue<pair<int,int>>q;
        //distance from src to itself is 0
        q.push({src,0});
        distance[src]=0;
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int node=p.first;
            int dist=p.second;
            vector<int>adjnodes=adj[node];
            for(int j=0;j<adjnodes.size();j++)
            {
                int adjnode=adjnodes[j];
                //+1 distance to travel to the adjacent node
                //if we get a distance that is shorter than the last one then add it
                //for smaller distances we add to both the distance vector & queue
                if(dist+1 < distance[adjnode])
                {
                    distance[adjnode]=dist+1;
                    q.push({adjnode,dist+1});
                }
            }
        }
}

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
{
        vector<vector<int>>adj(N);
        //there are M edges so store them in an adjacency list
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>distance(N,INT_MAX);
        shortestdist(N,src,adj,distance);
        //if any node is unreachable then it should be made -1
        for(int j=0;j<N;j++)
        {
            if(distance[j]==INT_MAX)
            {
                distance[j]=-1;
            }
        }
        return distance;
}
