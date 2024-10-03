#include <iostream>
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

    return 0;
}