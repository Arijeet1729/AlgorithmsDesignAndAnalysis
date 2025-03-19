/**
 * there exist a problem with this code 
 * the stack in MacBook Air M2 is not sufficient for running extremely large input
 * thus while execution do ulimit -s unlimited
 * this makes the stack size to unlimited
 */




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    vector<vector<int> > adj; // adjacency List
    vector<int> P; // Parent tree
    vector<int> visited; // if prev visited
    bool cycle_found; // impossible

public:
    /**
     * @brief Constructors (Makes an empty Graph of Size V)
     * @param V Cardinality of Vertex Set
     */
    Graph(int V) {
        this->adj.resize(V);
        P.resize(V, -1);
        visited.resize(V, false);
        cycle_found = false;
    }

    /**
     * @brief Adds undirected vertex from a to b
     * @param a Vertex 1
     * @param b Vertex 2
     */
    void add_edge(int a, int b) {
        a--; // Convert to 0-based index
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    /**
     * @brief Depth first traversal of a single node u
     * @param u Source node
     */
    bool DFS(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                P[v] = u;
                if (DFS(v)) {
                    return true;
                }
            } else if (v != P[u]) {  // Cycle detected
                printCycle(u, v);
                cycle_found = true;
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Depth first traversal for all the nodes
     */
    void full_DFS() {
        int V = adj.size();
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                if (DFS(u)) return;
            }
        }
        if (!cycle_found) {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    void printCycle(int u, int v) {
        vector<int> cycle;
        int temp = u;
        while (temp != v) {
            cycle.push_back(temp);
            temp = P[temp];
        }
        cycle.push_back(v);
        cycle.push_back(u);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int node : cycle) {
            cout << node + 1 << " "; // Convert back to 1-based index
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }
    g.full_DFS();
    return 0;
}