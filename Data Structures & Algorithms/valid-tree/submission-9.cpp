class Solution {
public:
    vector<int> parent;
    vector<int> sz;

    // return the root of x
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    // return true if a and b can unite
    bool unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if(rootA==rootB) return false;
        if(sz[rootA]<sz[rootB]) swap(rootA, rootB);
        parent[rootB] = rootA;
        sz[rootA]+=sz[rootB];
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        sz.assign(n,1);

        for(auto& edge : edges){
            if(!unite(edge[0],edge[1])) return false;
        }
        
        //walk through sz to check if all the nodes are connected
        // for(auto& num : sz){
        //     if(num==n) return true;
        // }
        return true;
    }
};

/*
valid tree
- acyclic, connected

build graph
start from any node( say node 0 )

DSU??? undirected graph detecting loops???



*/