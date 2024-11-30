Problem: https://leetcode.com/problems/course-schedule/description/

/*
We need to check if we can find a topological sort for the graph
If we think of it as a graph, we need to check if there are no cycles
And we can use Kahn's algorithm to check for cycles in the directed graph

Course Schedule I: just return T/F whether it's possible to schedule the courses
Course Schedule II: schedule the courses and return the topo sort order otherwise return {} if not possible to schedule
*/

//Course Schedule I
void checkcycle(int n, vector<vector<int>>&adj, vector<int>&indegree, vector<int>&kahns)
{
        for(int i=0;i<n;i++)
        {
            vector<int>adjnodes=adj[i];
            for(int j=0;j<adjnodes.size();j++)
            {
                indegree[adjnodes[j]]++;
            }
        }
        queue<int>q;
        for(int k=0;k<n;k++)
        {
            if(indegree[k]==0)
            {
                q.push(k);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            kahns.push_back(node);
            for(int l=0;l<adj[node].size();l++)
            {
                int adjnode=adj[node][l];
                indegree[adjnode]--;
                if(indegree[adjnode]==0)
                {
                    q.push(adjnode);
                }
            }
        }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        int n=adj.size();
        vector<int>indegree(n,0);
        vector<int>kahns;
        checkcycle(n, adj, indegree, kahns);
        //topo sort exists then no cycle so course schedule possible
        if(kahns.size()==numCourses)
        {
            return true;
        }
        return false;
}

// Course Schedule II
void toposort(int n, vector<vector<int>>&adj, vector<int>&indegree, vector<int>&kahns)
{
        for(int i=0;i<n;i++)
        {
            vector<int>adjnodes=adj[i];
            for(int j=0;j<adjnodes.size();j++)
            {
                indegree[adjnodes[j]]++;
            }
        }
        queue<int>q;
        for(int k=0;k<n;k++)
        {
            if(indegree[k]==0)
            {
                q.push(k);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            kahns.push_back(node);
            for(int l=0;l<adj[node].size();l++)
            {
                int adjnode=adj[node][l];
                indegree[adjnode]--;
                if(indegree[adjnode]==0)
                {
                    q.push(adjnode);
                }
            }
        }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        int n=adj.size();
        vector<int>indegree(n,0);
        vector<int>kahns;
        toposort(n,adj,indegree,kahns);
        //cycle found so topo sort is not for all n elements
        //in that case its impossible to schedule & finish all courses
        if(kahns.size()<n)
        {
            return {};
        }
        return kahns;
}
