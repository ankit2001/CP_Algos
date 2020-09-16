#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        int n;
        cin >> n;
        vector<int> adj[n];
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> euler;
        vector<bool> vis(n, false);
        function<void(int)> euler_tour = [&] (int v) {
            vis[v] = true;
            for (auto x: adj[v]) {
                if (!vis[x]) {
                    euler.push_back(v);
                    euler_tour(x);
                }
            }
            euler.push_back(v);
        };
        euler_tour(0);
        for (auto x: euler) {
            cout << x << " ";
        } cout << endl;
    }
}