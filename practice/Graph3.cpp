#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Graph{
    public:
        int arr[100][100];
        int n = 0;
        Graph(int n){
            this->n = n;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    arr[i][j] = 0;
                }
            }
        }
        void addGraph(int src , int dest , int weight){
            arr[src][dest] = weight;
        }
        void bfs(int start){
            vector<bool> visited(n , false);
            queue<int> q;
            q.push(start);
            while (!q.empty())
            {
                int current = q.front();
                q.pop();
                cout << current << " ";
                for(int i = 0 ; i < n ; i++){
                    if(arr[current][i] > 0 && !visited[i]){
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
            
        }
        void dfs(int start){
            vector<bool> visited(n , false);
            dfsHelper(start, visited);
        }
        void dfsHelper(int current , vector<bool> &visited){
            visited[current] = true;
            cout << current << " ";
            for(int i = 0 ; i < n ; i++){
                if(arr[current][i] > 0 && !visited[i]){
                    dfsHelper(i , visited);
                }
            }
        }
};
int main(){
        Graph g(5);
    // Adding edges to the graph (directed with weights)
    g.addGraph(0, 1, 1);
    g.addGraph(0, 2, 1);
    g.addGraph(1, 3, 1);
    g.addGraph(2, 3, 1);
    g.addGraph(3, 4, 1);
    
    // Test BFS and DFS
    cout << "BFS from node 0: ";
    g.bfs(0);  // Expected output: 0 1 2 3 4

    cout << "\nDFS from node 0: ";
    g.dfs(0);  // Expected output: 0 1 3 4 2
    return 0;    
}