#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct Edge{
    int a,b;
    int w;
}Edge;

bool operator<(const Edge &e1, const Edge &e2){
    return e1.w<e2.w;
}


class DSU
{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int V){
        parent.assign(V,-1);
        rank.assign(V,0);
        for(int i=0; i<V;i++){
            parent[i]=i;
        }
    }
    int find(int i){
        return (i==parent[i])?i : (parent[i]=find(parent[i]));
    }

    bool Union(int i, int j){
        int ip=find(i);
        int jp=find(j);
        if(ip==jp){
            return false;
        }
        if(rank[ip]<rank[jp]){
            parent[ip]=jp;
        }else if (rank[ip]>rank[jp]){
            parent[jp]=ip;
        }else{
            parent[jp]=ip;
            rank[ip]++;
        }
        return true;
    }
};

class Graph
{
private:
    int V;
    vector<Edge> adj;
public:
    Graph(int V) : V(V) {}

    void addEdge(int a, int b, int c){
        adj.push_back({a,b,c});
    }
    int Kruskal(){
        sort(adj.begin(),adj.end());
        DSU set(V);

        int mst_cost=0;
        for(auto u:adj){
            if(set.Union(u.a,u.b)) 
            {
                mst_cost+=u.w;
            };
            
        }
        return mst_cost;
    }
};


int main() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 2);
    
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    
    cout<<g.Kruskal()<<endl;

    return 0;
}