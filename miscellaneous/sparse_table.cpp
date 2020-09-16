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
        auto arr = vector(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int log = log2(n);
        auto table = vector(n, vector(log + 1, LLONG_MAX));
        int power[log + 1];
        for (int i = 0; i <= log; i++) {
            power[i] = (1 << i);
        }
        function<void(void)> build = [&] () {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= log; j++) {
                    if (j == 0) {
                        table[i][0] = arr[i];
                    } else {
                        if (i - power[j - 1] >= 0 and i - power[j] + 1 >= 0){
                            table[i][j] = table[i - power[j - 1]][j - 1] + table[i][j - 1];
                        }
                    }
                }
            }
        };
        function<int(int, int)> query = [&] (int l, int r) {
            if (l > r) {
                swap(l, r);
            }
            int diff = r - l + 1;
            int ans = 0, x = r;
            for (int i = log; i >= 0; i--) {
                if ((diff >> i) & 1) {
                    ans += table[r][i];
                    r = r - power[i];
                }
            }
            return ans;
        };
        build();
        for (auto x: table) {
            for (auto y: x) {
                cout << y << " ";
            } cout << "\n";
        }
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << endl;
    }
}