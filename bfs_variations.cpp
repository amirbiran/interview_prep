// Applications of BFS: https://www.geeksforgeeks.org/applications-of-breadth-first-traversal/

// 1.) Find shortest path length from source to destination
// 2.) Find shortest path from source to destination
// 3.) Find shortest path length from source to all nodes
// 4.) Find shortest paths from source to all nodes
// 5.) Check if a graph is bi-partite (2-colorable)


// 1 + 2: (3 + 4 if removing dest and returning dists)

int shortestPathLenHelper(vector<vector< int> > &graph, int source, int dest) {
  vector<bool> visited(graph.size(), false);
  list<int> bfs_q;
  vector<int> dists(graph.size(), INT_MAX), par(graph.size(), -1);
  bfs_q.push_back(source);
  dists[source] = 0;
  while(!bfs_q.empty()) {
    int curr = bfs_q.front();
    if(curr == dest) {
      return dists[dest];
    }
    bfs_q.pop_front();
    visited[curr] = true;
    for(int nei : graph[curr]) {
      if(!visited[nei]) {
        dists[nei] = dists[curr] + 1;
        par[nei] = curr;
        bfs_q.push_back(nei);
      }
    }
  }
  return -1; // path doesn't exist
}



// 5:



