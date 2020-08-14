#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> edge;
    int d[n];
    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        edge[{x, y}] = w;
    }
    auto bellman_ford = [&] (int source) {
        d[source] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (auto x: edge) {
                int start = x.first.first;
                int end = x.first.second;
                int w = x.second;
                if (d[end] > d[start] + w) {
                    d[end] = d[start] + w;
                }
            }
        }
    };
    bellman_ford(0);
    for (int i = 1; i < n; i++) {
        cout << d[i] << " ";
    } cout << "\n";
}