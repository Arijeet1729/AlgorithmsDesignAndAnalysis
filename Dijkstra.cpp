#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Define a pair to store (distance, node)
typedef pair<int, int> pii;

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<pii>>& graph, int src, int target) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);  // Initialize distances to infinity
    vector<int> parent(V, -1);     // To store the predecessor of each node
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap priority queue

    // Distance to the source node is 0
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();

        // If the current distance is greater than the stored distance, skip
        if (current_dist > dist[u]) continue;

        // If we reach the target node, stop early
        if (u == target) break;

        // Iterate through all adjacent vertices of u
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;  // Update the predecessor of v
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distance to the target node
    cout << "Shortest distance from " << src << " to " << target << " is: " << dist[target] << endl;

    // Reconstruct and print the path
    if (dist[target] == INT_MAX) {
        cout << "No path exists from " << src << " to " << target << endl;
    } else {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
}

int main() {
    // Example graph represented as an adjacency list
    int V = 5;  // Number of vertices
    vector<vector<pii>> graph(V);

    // Adding edges to the graph
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    int src = 0;  // Source node
    int target = 4;  // Target node
    dijkstra(graph, src, target);

    return 0;
}