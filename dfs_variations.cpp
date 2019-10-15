
// 1.) get all reachables from source node.
// 2.) discover circles.
// 3.) topological sort in DAG.
// 4.) get longest paths from source node in DAG using topological sort.
// 5.) get all fully connected components of a directed graph.


// 1 + 2:

enum NodeState {
  BLANK,
  VISITING,
  VISITED
};

vector<NodeState> node_states;
list<int> path;

bool dfsHelper(vector<vector<int> > &g, int n) {
  // 2:
  if(node_states[n] == VISITING) {
    return true; // Has circle
  }
  node_states[n] = VISITING;
  for(int nei : g[n]) {
    // Alternatively can keep dfs as void, have an external bool variable passed by reference, 
    // and keep checking for reachables.
    if(node_states[n] == BLANK && dfsHelper(g, nei)) {
      return true; // Found circle
    }
  }
  // 1:
  node_states[n] = VISITED;
  return false;
}

bool dfs(vector<vector<int> > &graph, int source) {
  node_states = vector<NodeState>(graph.size(), BLANK);
  // Return value true: has circle. Else, visited holds information of all reachables from source.
  return dfsHelper(graph, source); 
}



// 3:

// Popping "sorted" after method call yields topological sort of the DAG.
// Alternatively, can use list<int> or vector<int> and use push_back(n) to get quick access to other path parts. 
stack<int> sorted;

vector<bool> visited;

// Alternatively, the graph could be weighted: vector<vector<pair<int,int> > >, and we ignore the weight for TS.
void topologicalSortHelper(vector<vector<int> > &g, int n) {
  for(const int& nei : g[n]) {
    if(!visited[nei]) {
      topologicalSortHelper(g,nei);
    }
  }
  visited[n] = true;
  sorted.push(n);
}

void topologicalSort(vector<vector<int> > &graph) {
  visited = vector<bool>(graph.size(), false);
  sorted = stack<int>();
  // Return value true: has circle. Else, visited holds information of all reachables from source.
  topologicalSortHelper(graph, 0); 
}



// 4:

stack<int> sorted;

// Assuming the edge pair is of the form (j, weight)
// Alternatively, the graph could be unweighted, and we just use 1 as constant weight.
vector<int> longestPaths(vector<vector<pair<int,int> > > &graph, int source) {
  vector<int> longest_paths(graph.size(), -1);
  longest_paths[source] = 0;
  topologicalSort(graph); // Assume exists for weighted graph
  while(!sorted.empty()) {
    int n = sorted.top();
    sorted.pop();
    if(longest_paths[n] != -1) {
      for(int i=0; i < graph[n].size(); ++i) {
        int nei = graph[n][i].first;
        int w = graph[n][i].second;
        longest_paths[nei] = max(longest_paths[nei], longest_paths[n] + w);
      }
    }
  }
  return longest_paths;
}

// See more in: https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

// 5:

/*
  We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. 
  Following is detailed Kosaraju’s algorithm.
  1) Create an empty stack ‘S’ and do DFS traversal of a graph. 
  In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. 
  2) Reverse directions of all arcs to obtain the transpose graph.
  3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. 
  Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. 
  Use a "visited" vector to avoid moving to already seen neighbhors in previous DFSUtil runs.
  
  See more in: https://www.geeksforgeeks.org/strongly-connected-components/
*/

