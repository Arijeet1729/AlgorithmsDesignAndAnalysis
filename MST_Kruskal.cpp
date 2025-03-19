
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight, index;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    vector<int> result(E);
    
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].index = i;
    }
    
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end());
    
    DSU dsu(V + 1);
    int mstWeight = 0;
    vector<bool> inMST(E, false);
    
    for (const auto &edge : sortedEdges) {
        if (dsu.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            inMST[edge.index] = true;
        }
    }
    
    for (int i = 0; i < E; i++) {
        if (inMST[i]) {
            result[i] = mstWeight;
        } else {
            DSU tempDsu(V + 1);
            int tempWeight = 0;
            
            tempDsu.unite(edges[i].u, edges[i].v);
            tempWeight += edges[i].weight;
            
            for (const auto &edge : sortedEdges) {
                if (edge.index == i) continue;
                if (tempDsu.unite(edge.u, edge.v)) {
                    tempWeight += edge.weight;
                }
            }
            result[i] = tempWeight;
        }
    }
    
    for (int i = 0; i < E; i++) {
        cout << result[i] << "\n";
    }
    
    return 0;
}