/*
Approach:
Using Dijkstra's Algorithm we are storing {weight/distance, node} from the start node
Now a "parent" vector is created to store the parent of each node as we move ahead
This way we can backtrack and trace the path by tracing the parent of each node
TC: O((n+m)logn) -> simple Dijkstra's algorithm
SC: O(n+m) + O(n) + O(n) + O(n) -> adj list + parent/distance array + PQ + "path" vector
*/

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
{
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++)
        {
            int node1=edges[i][0];
            int node2=edges[i][1];
            int weight=edges[i][2];
            adj[node1].push_back({node2,weight});
            adj[node2].push_back({node1,weight});
        }
        vector<int>distance(n+1,INT_MAX);
        vector<int>parent(n+1,-1);
        int start=1, end=n;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,start});
        distance[start]=0;
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            int node=p.second;
            int dist=p.first;
            pq.pop();
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
                    pq.push({newdist,adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        vector<int>path;
        int pathnode=end;
        //node cant be reached
        if(distance[pathnode]==INT_MAX)
        {
            return {-1};
        }
        while(pathnode!=start)
        {
            path.push_back(pathnode);
            pathnode=parent[pathnode];
        }
        path.push_back(start);
        reverse(path.begin(),path.end());
        //sum of edge weights calculated
        int pathWeight = 0;
        for (int i=1;i<path.size();i++) 
        {
            int u=path[i-1];
            int v=path[i];
            for(auto& edge : adj[u]) 
            {
                if(edge.first == v) 
                {
                    pathWeight+=edge.second;
                    break;
                }
            }
        }
        //if not matched then return -1
        if(pathWeight!=distance[end]) 
        {
            return {-2};
        }
        path.insert(path.begin(), pathWeight);
        return path;
}
