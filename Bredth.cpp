#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Graph{
    private:
        int V;
        vector< vector<int> > adj;
        vector< vector <int> > levelset;
        vector <int> parent;
        vector <int> distance;
        
    public:
        Graph (int n){
            V=n;
            adj.resize(n);
            levelset.resize(n);
            parent.assign(n,-1);
            
            distance.assign(n,INT_MAX);
        }
        
        void addEdge(int a, int b){
            adj[a].push_back(b);
            adj[a].push_back(b);
        }
        int BFS(int s, int t){
            levelset[0].push_back(s);
            distance[s]=0;
            parent[s]=s;

            int i=1;
            while (!levelset[i-1].empty()){
                for(int u:levelset[i-1]){
                    for(auto v: adj[u]){
                        if (parent[v]==-1){
                            parent[v]=u;
                            levelset[i].push_back(v);
                            distance[v]=i;
                        }
                    }
                    i++;
                }
            }
            return distance[t];
            
        }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS traversal: ";
   cout<<g.BFS(0,4);
    cout << endl;

    return 0;
}