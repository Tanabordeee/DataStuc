#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Graph
{
public:
    int matrix[100][100];
    int n;
    Graph(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    void addEdge(int src, int dest, int weight)
    {
        matrix[src][dest] = weight;
    }
    void print()
    {
        cout << "    ";
        for (int i = 0; i < n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] > 0)
                {
                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    void bfs(int start){
        vector<bool> visited(n , false);
        queue<int> queue;
        visited[start] = true;
        queue.push(start);
        while(!queue.empty()){
            int current = queue.front();
            queue.pop();
            cout << current << " ";

            for(int i = 0; i < n; i++){
                if(matrix[current][i] > 0 && !visited[i]){
                    visited[i] = true;
                    queue.push(i);
                }
            }
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 0, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 1, 1);
    g.print();
    cout << "BFS starting from node 0: ";
    g.bfs(0); // Start BFS from node 0
    cout << endl;
    return 0;
}