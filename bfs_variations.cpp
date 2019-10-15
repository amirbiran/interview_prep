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

enum Color {
  BLANK,
  BLUE,
  RED
};

bool isBipartiteGraph(vector<vector<int> > &graph) {
  // Assume graph is undirected. If not, we can turn it undirected. 
  vector<Color> colors(graph.size(), BLANK);
  list<int> bfs_q;
  
  for(int n=0; n < graph.size(); ++n) {
    if(colors[n] == BLANK) { // Choose uncolored source from the graph
      colors[n] = BLUE; // First node in component, arbitrarily color it blue.
      bfs_q.push_back(n);
      while(!bfs_q.empty()) {
        int n = bfs_q.front();
        bfs_q.pop_front();
        for(int nei : graph[n]) {
          if(colors[nei] == colors[n]) {
            return false;  
          }
          if(colors[nei] == BLANK) {
            if(colors[n] == BLUE) {
                colors[nei] = RED;
            } else {
                colors[nei] = BLUE;
            }
            bfs_q.push_back(nei);
          }
        }
      }
    }
  }
  return true;
}







