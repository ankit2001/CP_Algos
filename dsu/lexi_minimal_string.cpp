#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    //cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        string a, b, c;
        cin >> a >> b >> c;
        int arr[26], mini[26], size[26];
        for (int i = 0; i < 26; i++) {
            arr[i] = i;
            size[i] = 1;
            mini[i] = i;
        } 
        auto root = [&] (int x) {
            while (x != arr[x]) {
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
                mini[root_y] = min(mini[root_y], mini[root_x]);
            } else {
                arr[root_y] = arr[root_x];
                size[root_x] += size[root_y];
                mini[root_x] = min(mini[root_y], mini[root_x]);
            }
            return ;
        };

        for (int i = 0; i < a.length(); i++) {
            int x = int(a[i] - 'a');
            int y = int(b[i] - 'a');
            Union(x, y);
        }
        string ans = "";
        for (int i = 0; i < c.length(); i++) {
            int root_x = root(int(c[i] - 'a'));
            ans += char(mini[root_x] + 'a');
        }
        cout << ans << "\n";
    }
}