#include<bits/stdc++.h>
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
        vector<vector<int>> adj(M);
        for (int i = 0; i < M; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            x--, y--;
            adj[i] = {x, y, w};
        }
        int arr[N], size[N];
        for (int i = 0; i < N; i++) {
            arr[i] = i;
            size[i] = i;
        }
        auto root = [&] (int x) {
            while(x != arr[x]) {
                arr[x] = arr[arr[x]];
                x = arr[x];
            }
            return x;
        };
        auto find = [&] (int x, int y) {
            return root(x) == root(y);
        };
        auto Union = [&] (int x, int y) {
            int root_x = root(x);
            int root_y = root(y);
            if (size[root_x] < size[root_y]) {
                arr[root_x] = arr[root_y];
                size[root_y] += size[root_x];
            } else {
                arr[root_y] = arr[root_x];
                size[root_x] += size[root_y];
            }
            return;
        };
        sort(adj.begin(), adj.end(), [&] (vector<int> v1, vector<int> v2) {
            return v2[2] > v1[2];
        });
        int cost = 0;
        for (int i = 0; i < M; i++) {
            int x = adj[i][0], y = adj[i][1], w = adj[i][2];
            int root_x = root(x);
            int root_y = root(y);
            if (arr[root_x] == arr[root_y]) {
                continue;
            }
            cost += w;
            Union(x, y);
        }
        cout << cost << "\n";
    }
}