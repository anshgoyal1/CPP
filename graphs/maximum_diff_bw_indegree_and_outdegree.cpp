#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int get_vertex(unordered_map<int, int> &outdegree, unordered_map<int, int> &indegree, int len)
{
    int max = outdegree[0] - indegree[0], vertex = 0;
    for (int i = 1; i < len; i++)
    {
        if (outdegree[i] - indegree[i] > max)
        {
            max = outdegree[i] - indegree[i];
            vertex = i;
        }
    }
    return vertex;
}

int main()
{
    int n, vertex, destination;
    cin >> n;

    unordered_map<int, int> indegree, outdegree;
    for (int i = 0; i < n; i++)
    {
        cin >> vertex;
        while (1)
        {
            cin >> destination;
            if (destination == -1)
                break;

            outdegree[i] += 1;
            indegree[destination] += 1;
        }
    }

    cout << get_vertex(outdegree, indegree, n);
    return 0;
}