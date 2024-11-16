Learnings & Common Mistakes:

1. Graph Valid Tree - A graph is a valid tree when - 1 connected component + no cycles in the graph

2. If given edges = [[0,1],[0,2],[0,3],[1,4]] that represent edges between 2 nodes, then while converting to adjacency list, take the size of edges m=edges.size() to iterate and create the adjacency list, don't take the number of vertices n, because the number of vertices and edges are not same and might give an error.

4. Always define the size of the vector while creating an adjacency list and visited vectors, like vector<vector<int>>adj(n); vector<int>visited(n,0);

5. Cycle Detection in an undirected graph using DFS is done using only the visited vector, and Cycle Detection in a directed graph using DFS is done using visited + pathvisited. Because in a directed graph we need to check if the node was visited in the same path as the current path. Cycle Detection in an undirected graph using BFS 
