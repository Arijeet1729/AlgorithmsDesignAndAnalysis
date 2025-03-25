#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;
using pii = pair<int,int>;

class Graph{
    private:
        int V;
        vector<vector<int>> adj;
        vector<vector<int>> weight;
        vector <vector<int>> distance;
        set <pair<int,int>> pq;
        
    public:
        Graph(int n){
            this->V=n;
            adj.resize(n);
            weight.assign(n, vector<int>(n, INT_MAX));
            distance.assign(n, vector<int>(n, INT_MAX));
        }
    
        void addEdge(int a, int b, int w){
            adj[a].push_back(b);
            weight[a][b]=w;
        }
        void changePriority(int newPriority,int val){ 
            
            set<pair<int,int>>::iterator it=pq.begin();
            while(it!=pq.end()){
                if (it->second == val) {
                    pq.erase(it);
                    break;
                }
                ++it;
            }
            pq.insert({newPriority, val});
        }
        
        pair<int, int> extractMin(){
            auto i= *pq.begin();
            pq.erase(pq.begin());
            return i;
        }
        
        void relax(int s, int u, int v){
            if(distance[s][v]>distance[s][u]+weight[u][v]){
                distance[s][v]=distance[s][u]+weight[u][v];
                
                changePriority(distance[s][v],v); 
            }
        }
        
        int Dijkstra(int s, int t){
            distance[s][s]=0;
            pq.insert({0,s});
            
            while(!pq.empty()){
                int u=extractMin().second;
                for(auto v: adj[u]){
                    relax(s,u,v);
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
    cout << "Shortest Distance from " << s << " to " << t << " is " << shortestDistance << endl;

    return 0;
}