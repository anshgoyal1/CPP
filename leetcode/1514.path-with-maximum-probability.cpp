/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {

            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }

        const double inf = 1e9;
        vector<double> dist(n, (double)0.0);
        vector<bool> visited(n, false);

        priority_queue<pair<double, int>> pq;
        pq.push(make_pair((double)1.0, start));
        dist[start] = 1.0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            double prob1 = pq.top().first;

            if (visited[u])
                continue;
            visited[u] = true;

            for (auto it : adj[u])
            {
                int v = it.first;
                double prob = it.second;

                if (dist[v] < prob1 * prob)
                {
                    // cout << dist[u] * prob << endl;
                    cout << prob << " " << prob1 << endl;
                    dist[v] = prob * prob1;
                    // cout << dist[v] << endl;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        for (auto it : dist)
        {
            cout << it << " ";
        }
        return dist[end];
    }
};
// @lc code=end
