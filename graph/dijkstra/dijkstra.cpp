#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            x--, y--;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        bool vis[n];
        memset(vis, false, sizeof(vis));
        int d[n];
        for (int i = 0; i < n; i++) {
            d[i] = INT_MAX;
        }
        auto dijkstra = [&] (int source) {
            d[source] = 0;
            vis[source] = true;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            q.push({0, source});
            while(!q.empty()) {
                pair<int, int> p = q.top();
                q.pop();
                int dist = p.first, idx = p.second;
                vis[p.second] = true;
                for (auto x: adj[idx]) {
                    if (!vis[x.first]) {
                        if (d[x.first] > dist + x.second) {
                            d[x.first] = dist + x.second;
                            q.push({d[x.first], x.first});
                        }
                    }
                }
            }
            return;
        };
        dijkstra(0);
        for (int i = 1; i < n; i++) {
            cout << d[i] << " ";
        } cout << "\n";
    }
}