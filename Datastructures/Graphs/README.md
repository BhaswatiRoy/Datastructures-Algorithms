Learnings & Common Mistakes:

1. If given edges = [[0,1],[0,2],[0,3],[1,4]] that represent edges between 2 nodes, then while converting to adjacency list, take the size of edges m=edges.size() to iterate and create the adjacency list, don't take the number of vertices n, because the number of vertices and edges are not same and might give an error.

2. Always define the size of the vector while created an adjacency list and visited vectors, like vector<vector<int>>adj(n); vector<int>visited(n,0);
