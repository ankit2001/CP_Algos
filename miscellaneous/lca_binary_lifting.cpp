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
        auto level = vector(n, 0);
        function<void(int)> binary_lifting = [&] (int v) {
            vis[v] = true;
            for (auto x: adj[v]) {
                if (!vis[x]) {
                    level[x] = level[v] + 1;
                    table[x][0] = v;
                    for (int i = 1; i <= log; i++) {
                        table[x][i] = table[table[x][i - 1]][i - 1];
                    }
                    binary_lifting(x);
                }
            } 
        };
        binary_lifting(0);
        function<int(int, int)> lca = [&] (int x, int y) {
            if (level[y] > level[x]) {
                swap(x, y);
            }
            int diff = level[x] - level[y];
            for (int i = log; i >= 0; i--) {
                if ((diff >> i) & 1) {
                    x = table[x][i];
                }
            }
            if (x == y) {
                return x;
            }
            for (int i = log; i >= 0; i--) {
                int l = table[x][i];
                int m = table[y][i];
                if (l != m) {
                    x = l;
                    y = m;
                }
            }
            return table[x][0];
        };
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << lca(x, y) << endl;
    }
}