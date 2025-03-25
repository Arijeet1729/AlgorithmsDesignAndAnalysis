
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU{
    private:
        vector <int> parent;
        vector <int> rank;
    public:
        DSU(int V){
            rank.assign(V,0);
            parent.assign(V,0);
            for(int i=0;i<V;i++){
                parent[i]=i;
            }
        }
        
        int findByPathCompression(int i){
            return (i==parent[i])? i : parent[i]=findByPathCompression(parent[i]);
        }
        
        bool unionByRank(int i , int j){
            int ip=findByPathCompression(i);
            int jp=findByPathCompression(j);
            
            if(ip==jp){
                return false;
            }
            if(rank[ip]<rank[jp]){
                parent[ip]=jp;
            }else if(rank[ip]>rank[jp]){
                parent[jp]=ip;
            }else{
                parent[jp]=ip;
                rank[ip]++;
            }
            return true;
        }
};

typedef struct Edge{
    int a,b,w;
}edge;


bool operator<(const edge &a, const edge &b){
    return a.w<b.w;
}

class Graph{
    private:
        int V;
        vector<edge> edges;
    public:
        Graph(int a){
            V=a;
        }
        void addEdge(int a, int b, int c){
            edges.push_back({a,b,c});
        }
        void KruskalMST(){
            sort(edges.begin(),edges.end());
            int mst_cost=0;
            vector<edge> e;
            
            DSU dset(V);
            
            for(auto i:edges){
                if(dset.unionByRank(i.a,i.b)){
                    mst_cost+=i.w;
                    e.push_back(i);
                }
            }
            cout<<mst_cost<<endl;
            
            for(auto i:e){
                cout<<i.a<<"---{"<<i.w<<"}---"<<i.b<<endl;
            }
        }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);

    g.KruskalMST();
    return 0;
}