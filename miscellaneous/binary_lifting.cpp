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
        int log = log2(n);
        auto table = vector(n, vector(log + 1, 0));
        auto vis = vector(n, 0);
        function<void(int)> binary_lifting = [&] (int v) {
            vis[v] = true;
            for (auto x: adj[v]) {
                if (!vis[x]) {
                    table[x][0] = v;
                    for (int i = 1; i <= log; i++) {
                        table[x][i] = table[table[x][i - 1]][i - 1];
                    }
                    binary_lifting(x);
                }
            }
        };
        binary_lifting(0);
        for (auto x: table) {
            for (auto y: x) {
                cout << y << " ";
            } cout << endl;
        }
    }
}