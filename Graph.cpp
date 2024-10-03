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
    void dft(int start){
        vector<bool> visited(n , false);
        dfthelper(start ,visited);
    }
    void dfthelper(int current , vector<bool>& visited){
        visited[current] = true;
        cout << current << " ";
        for(int i =  0 ; i < n ; i++){
            if(matrix[current][i] > 0 && !visited[i]){
                dfthelper(i , visited);
            }
        }
    }
};
int main()
{
    int n , vertex , vertex2 , weight , start;
    char input;
    cin >> n;
    Graph g(n);
    while(true){
        cin >> input;
        if(input == 'e'){
            cin >> vertex >> vertex2 , weight;
            g.addEdge(vertex , vertex2 , weight);
        }
        else if(input == 'd'){
            cin >> start;
            g.dft(start);
        }
        else if(input == 'b'){
            cin >> start;
            g.bfs(start);
        }
        else if(input == 'q'){
            break;
        }else if (input == 's'){}
    }
    return 0;
}