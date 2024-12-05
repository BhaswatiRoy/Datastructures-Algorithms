/*
Dijkstra's algorithm does not work on graphs with negative edge weights
on every traversal, distance reduces due to -ve weights 
& min heap priority queue keeps on storing them and this is an infinite loop

If we get a distance of 8 for node 5, and previously there was a distance of 10 for node 5
Using set means we can erase that (10, 5) and only store (8,5) but for priority queue we can't do it

There is no guarantee that set is a better approach because s.erase() takes O(logn) time 
This might save future operations and improve TC slightly 
When the graph is dense, and frequent updates are necessary then the set is better
If the graph is not dense then the priority queue is better

Approach 1: Using Priority Queue
1. Take a min heap priority queue to store {distance, node}
2. Push the source & distance 0 to queue
3. Create a "distance" vector with all values set to INT_MAX
4. Iterate through the queue like BFS and find the distance by adding them up
5. If we find, we can reach a node with a lesser distance than INT_MAX 
6. then store it in the queue, and also update the value in the "distance" vector
TC: O((V+E)logV) -> E = no of edges, V = no of vertices, inserting/extracting = logV
SC: O(V+E) + O(V) + O(V) -> adj list + distance array + priority queue

Approach 2: Using Set
The same as the PQ version.
When we find a better distance we erase the older version from the set, which is impossible in PQ.
This saves some time and iterations in the future for dense graphs.
TC: O((V+E)logV) ->  E = no of edges, V = no of vertices, inserting/extracting = logV
SC: O(V+E) + O(V) + O(V) -> adj list + distance array + priority queue
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


vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) 
{
        int n=adj.size();
        vector<int>distance(n,INT_MAX);
        //{distance, node} stored in set
        //to erase it later
        set<pair<int,int>>s;
        //distance from src to itself is 0
        s.insert({0,src});
        distance[src]=0;
        while(!s.empty())
        {
            //s.begin() returns iterator so we dereference it
            pair<int,int>p=*s.begin();
            int node=p.second;
            int dist=p.first;
            s.erase(s.begin());
            vector<pair<int,int>>adjnodes=adj[node];
            for(int i=0;i<adjnodes.size();i++)
            {
                pair<int,int>temp=adjnodes[i];
                int adjnode=temp.first;
                int adjdist=temp.second;
                int newdist=dist+adjdist;
                if(newdist<distance[adjnode])
                {
                    distance[adjnode]=newdist;
                    
                    //the only difference between PQ vs Set version
                    //we erase it to save some space
                    s.erase({distance[adjnode],adjnode});
                    
                    s.insert({newdist,adjnode});
                }
            }
        }
        return distance;
}
