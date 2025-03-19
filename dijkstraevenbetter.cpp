#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class MinHeap {
private:
    vector<pair<int, int>> h; // (distance, node)
    unordered_map<int, int> pos; // Maps node to heap index

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void swap(int i, int j) {
        pos[h[i].second] = j;
        pos[h[j].second] = i;
        std::swap(h[i], h[j]);
    }

    void shiftUp(int i) {
        while (i > 0 && h[i].first < h[parent(i)].first) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < h.size() && h[l].first < h[smallest].first) smallest = l;
        if (r < h.size() && h[r].first < h[smallest].first) smallest = r;

        if (smallest != i) {
            swap(i, smallest);
            shiftDown(smallest);
        }
    }

public:
    bool empty() { return h.empty(); }

    void insert(int key, int value) {
        pos[value] = h.size();
        h.push_back({key, value});
        shiftUp(h.size() - 1);
    }

    pair<int, int> extractMin() {
        pair<int, int> minNode = h[0];
        pos.erase(minNode.second);
        swap(0, h.size() - 1);
        h.pop_back();
        if (!h.empty()) shiftDown(0);
        return minNode;
    }

    void decreaseKey(int value, int newKey) {
        if (pos.find(value) == pos.end()) return;
        int i = pos[value];
        if (newKey >= h[i].first) return;
        h[i].first = newKey;
        shiftUp(i);
    }
};

class Graph {
private:
    int node;
    vector<vector<int>> adj;
    vector<vector<int>> weights;

public:
    Graph(int node) {
        this->node = node;
        adj.resize(node);
        weights.resize(node, vector<int>(node, INT_MAX));
    }

    void addEdge(int a, int b, int w) {
        adj[a].push_back(b);
        weights[a][b] = w;
    }

    int Dijkstra(int s, int t) {
        vector<int> distance(node, INT_MAX);
        MinHeap pq;
        distance[s] = 0;
        pq.insert(0, s);

        while (!pq.empty()) {
            auto [dist, u] = pq.extractMin();

            if (u == t) return dist;

            for (int v : adj[u]) {
                if (distance[v] > dist + weights[u][v]) {
                    distance[v] = dist + weights[u][v];
                    pq.decreaseKey(v, distance[v]);
                    pq.insert(distance[v], v);
                }
            }
        }
        return -1; // Unreachable
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
    cout << "Shortest distance from " << s << " to " << t << ": " << shortestDistance << endl;

    return 0;
}
