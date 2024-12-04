/*
Dijkstra's algorithm does not work on graphs with negative edge weights
on every traversal distance reduces due to -ve weights 
& min heap priority queue keeps on storing them and this is an infinite loop

Approach 1: Using Priority Queue
1. Take a min heap priority queue to store {distance, node}
2. Push the source & distance 0 to queue
3. Create a "distance" vector with all values set to INT_MAX
4. Iterate through the queue like BFS and find distance by adding them up
5. If we find, we can reach a node with lesser distance than INT_MAX 
6. then e store it in the queue, and also update the value in the "distance" vector
TC: ElogV -> E = no of edges, V = no of vertices
SC: 
*/

// Using Priority Queue
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) 
{
        int n=adj.size();
        vector<int>distance(n,INT_MAX);
        //{distance, node} stored in min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        //distance from src to itself is 0
        q.push({0,src});
        distance[src]=0;
        while(!q.empty())
        {
            pair<int,int>p=q.top();
            q.pop();
            int node=p.second;
            int dist=p.first;
            vector<pair<int,int>>adjnodes=adj[node];
            for(int j=0;j<adjnodes.size();j++)
            {
                pair<int,int>temp=adjnodes[j];
                int adjnode=temp.first;
                int adjdist=temp.second;
                int newdist=dist+adjdist;
                if(newdist<distance[adjnode])
                {
                    distance[adjnode]=newdist;
                    q.push({newdist,adjnode});
                }
            }
        }
        return distance;
}
