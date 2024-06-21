#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int bfs(int src, int sink, vector<int>& parent, vector<vector<int>>& res) {
    fill(parent.begin(), parent.end(), -1);
    int n = sink + 1;
    parent[src] = -2;
    queue<pair<int, int>> q;
    q.push({src, INT_MAX});

    while (!q.empty()) {
        int u = q.front().first;
        int capacity = q.front().second;
        q.pop();
        for (int it = 0; it < n; it++) {
            if (u != it && parent[it] == -1 && res[u][it] != 0) {
                parent[it] = u;
                int min_cap = min(capacity, res[u][it]);
                if (it == sink) {
                    return min_cap;
                }
                q.push({it, min_cap});
            }
        }
    }
    return 0;
}

int maximumMatch(vector<vector<int>> &G) {
    int N = G.size();
    int M = G[0].size();
    vector<vector<int>> graph(N + M + 2, vector<int>(N + M + 2, 0));
    for (int i = 1; i < N + 1; i++) {
        graph[0][i] = 1;
    }
    for (int i = N + 1; i < N + M + 1; i++) {
        graph[i][N + M + 1] = 1;
    }

    int x = 0;
    for (int i = 1; i < N + 1; i++) {
        int y = 0;
        for (int j = N + 1; j < N + M + 1; j++) {
            graph[i][j] = G[x][y];
            y++;
        }
        x++;
    }

    vector<int> parent(N + M + 2, -1);
    vector<vector<int>> res = graph;
    int min_cap = 0, max_flow = 0;
    while (bfs(0, N + M + 1, parent, res)) {
        min_cap = bfs(0, N + M + 1, parent, res);
        max_flow += min_cap;
        int u = N + M + 1;
        while (u != 0) {
            int v = parent[u];
            res[u][v] += min_cap;
            res[v][u] -= min_cap;
            u = v;
        }
    }
    return max_flow;
}
