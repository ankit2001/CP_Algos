#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        int N, M;
        cin >> N >> M;
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            x--, y--;
            adj[x].push_back({w, y});
            adj[y].push_back({w, x}); 
        }
        bool vis[N];
        memset(vis, false, sizeof(vis));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int cost = 0;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> p = q.top();
            q.pop();
            vis[p.second] = true;
            cost += p.first;
            for (auto x: adj[p.second]) {
                if (!vis[x.second]) {
                    q.push(x);
                }
            }
        }
        cout << cost << "\n";
    }
    return 0;
}
