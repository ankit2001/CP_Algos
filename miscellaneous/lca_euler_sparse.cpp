#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
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
        unordered_map<int, int> mp;
        for (int i = 0; i < euler.size(); i++) {
            mp[euler[i]] = i;
        }
        int size = euler.size();
        int log = log2(size);
        auto table = vector(size, vector(log + 1, LLONG_MAX));
        int power[size];
        for (int i = 0; i < size; i++) {
            power[i] = (1 << i);
        }
        function<void(void)> build = [&] () {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j <= log; j++) {
                    if (j == 0) {
                        table[i][j] = euler[i];
                    } else {
                        if (i - power[j] + 1 >= 0 and i - power[j - 1] >= 0) {
                            table[i][j] = min(table[i][j - 1], table[i - power[j - 1]][j - 1]);
                        }
                    }
                }
            }
        };
        build();
        function<int(int, int)> query = [&] (int l, int r) {
            if (l > r) {
                swap(l, r);
            } 
            int msb = log2(r - l + 1);
            return min(table[r][msb], table[l + power[msb] - 1][msb]);
        };
        function<int(int, int)> lca = [&] (int x, int y) {
            int l = mp[x], r = mp[y];
            return query(l, r);
        };
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << lca(x, y) << "\n";
    }
}