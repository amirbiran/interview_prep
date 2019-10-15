// Mostly written by "nc_" in https://leetcode.com/problems/number-of-islands-ii/discuss/375428/My-C%2B%2B-Solution-using-Union-Find


// struct - no private fields / methods
struct UnionFind {
    // parents vector and rank vector - upside down trees with union by rank.
    vector<int> par, rank;
    
    UnionFind(int N): par(N), rank(N, 0) { // Initial rank is 0 for every element
        // Initial parent for every element i is itself (meaning he is the leader of his group)
        for (int i = 0; i < N; ++i) par[i] = i;
    }
    
    int find(int i) {
        // if i is its own parent, he is the leader of his group, so return him. o.w, go up his tree until the leader is found.
        return (par[i] != i) ? (par[i] = find(par[i])) : par[i];
    }
    
    // "union" method name not available, using "doUnion" instead.
    bool doUnion(int i, int j) {
        // Get the leaders of i and j, pi and pj respectively
        int pi = find(i), pj = find(j);
        // If leaders are same, return false, since no union is required.
        if (pi == pj) return false;
        // if pj has greater rank, it become pi's parent
        if (rank[pi] < rank[pj])  {
            rank[pj] += (rank[pi] == rank[pj]); // If their rank is equal, the new tree will have rank 1 higher 
            par[pi] = pj;
        } else {
            // else, pi has greater rank, it become pj's parent
            rank[pi] += (rank[pi] == rank[pj]); // If their rank is equal, the new tree will have rank 1 higher 
            par[pj] = pi;
        }
        // Union performed de-facto, return true.
        return true;
    }
};
