#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Graph{
    private:
        int V;
        vector<vector<int>> distance;
    public:
        Graph(int v){
            this->V=v;
            distance.assign(v,vector<int>(v,INT_MAX));
        }
        void addEdge(int a, int b, int c){
            distance[a][b]=c;
        }
        
        void floydWarshall(){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    for(int k=0;k<V;k++){
                        if(distance[i][k]!=INT_MAX &&
                        distance[k][j]!=INT_MAX){
                            distance[i][j]=min(distance[i][j],
                            distance[i][k]+distance[k][j]);
                        }
                    }
                }
            }
        }
 
    void printSolution() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (distance[i][j] == INT_MAX) {
                    cout << "oo ";
                } else {
                    cout << " " <<distance[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(3, 2, 1);

    g.floydWarshall();
    g.printSolution();

    return 0;
}
