#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Graph {
private:
    int node;
    vector<vector<int>> adj;
    vector<vector<int>> weights;
    vector<vector<int>> distance;
    set<pair<int, int>> pq;

public:
    Graph(int node) {
        this->node = node;
        adj.resize(node);
        weights.resize(node, vector<int>(node, INT_MAX));
        distance.resize(node, vector<int>(node, INT_MAX));
    }

    void addEdge(int a, int b, int w) {
        adj[a].push_back(b);
        weights[a][b] = w;
    }

    void changePriority(int nodeval, int newPriority) {
        for (auto it = pq.begin(); it != pq.end(); ++it) {
            if (it->second == nodeval) {
                pq.erase(it);
                break;
            }
        }
        pq.insert({newPriority, nodeval});
    }

    pair<int, int> extractMin() {
        auto minNode = *pq.begin();
        pq.erase(pq.begin());
        return minNode;
    }

    void relaxEdge(int s, int u, int v) {
        if (distance[s][v] > distance[s][u] + weights[u][v]) {
            distance[s][v] = distance[s][u] + weights[u][v];
            changePriority(v, distance[s][v]);
        }
    }

    int Dijkstra(int s, int t) {
        distance[s][s] = 0;
        pq.insert({0, s}); 

        while (!pq.empty()) {
            auto [dist, u] = extractMin();

            if (u == t) return dist; 

            for (int v : adj[u]) {
                relaxEdge(s, u, v);
            }
        }

        return (distance[s][t] == INT_MAX) ? -1 : distance[s][t];
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(3, 1, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 2, 9);

    int s = 0, t = 2;
    int shortestDistance = g.Dijkstra(s, t);
    cout << "SD " << s << " to " << t << " is " << shortestDistance << endl;

    return 0;
}
