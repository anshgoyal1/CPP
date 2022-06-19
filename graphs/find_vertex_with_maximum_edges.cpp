#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int vertex, int destination)
{
    adj[vertex].push_back(destination);
    adj[destination].push_back(vertex);
    return;
}

int get_vertex(vector<int> adj[], int len)
{
    int max = adj[0].size(), vertex = 0;
    for (int i = 1; i < len; i++)
    {
        if (adj[i].size() > max)
        {
            max = adj[i].size();
            vertex = i;
        }
    }
    return vertex;
}

int main()
{
    int n, vertex, destination;
    cin >> n;

    vector<int> adjacency_list[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vertex;
        while (1)
        {
            cin >> destination;
            if (destination == -1)
                break;
            addEdge(adjacency_list, vertex, destination);
        }
    }

    cout << get_vertex(adjacency_list, n);
    return 0;
}