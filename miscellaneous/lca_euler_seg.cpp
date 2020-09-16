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
        int size = euler.size();
        for (int i = 0; i < size; i++) {
            mp[euler[i]] = i;
        }
        vector<int> st(4 * size + 1, INT_MAX);
        function<void(int, int, int)> build = [&] (int l, int r, int v) {
            if (l > r) {
                return;
            } 
            if (l == r) {
                st[v] = euler[l];
                return ;
            }
            int mid = (l + r) >> 1;
            build(l, mid, 2 * v + 1);
            build(mid + 1, r, 2 * v + 2);
            st[v] = min(st[2 * v + 1], st[2 * v + 2]);
        };
        build(0, size - 1, 0);
        function<int(int, int, int, int, int)> query = [&] (int l, int r, int v, int tl, int tr) {
            if (l > tr or r < tl) {
                return INT_MAX;
            } 
            if (l >= tl and r <= tr) {
                return st[v];
            }
            int mid = (l + r) >> 1;
            int ans1 = query(l, mid, 2 * v + 1, tl, tr);
            int ans2 = query(mid + 1, r, 2 * v + 2, tl, tr);
            return min(ans1, ans2);
        };
        function<int(int, int)> lca = [&] (int x, int y) {
            int l = mp[x], r = mp[y];
            if (l > r) {
                swap(l, r);
            }
            return query(0, size - 1, 0, l, r);
        };
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << lca(x, y) << endl;
    }
}