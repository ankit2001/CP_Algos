#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  while (cin >> s) {
    if (s == "0") {
      break;
    }
    int len = s.length();
    long long dp[len + 1];
    bool vis[len + 1];
    memset (vis, false, sizeof(vis));
    function <long long(int)> alphacode = [&] (int n) {
      if(n >= len) {
        return 1ll;
      }
      auto &ans = dp[n];
      auto &seen = vis[n];
      if (!seen) {
        seen = true;
        if (n == len - 1) {
          if (s[n] != '0') {
            ans = 1ll;
          } else {
            ans = 0ll;
          }
          return ans;
        }
        if (s[n] == '0') {
          return 0ll;
        }
        if (s[n + 1] == '0') {
          ans = alphacode(n + 2);
          return ans;
        } else {
          ans = alphacode(n + 1);
          if ((s[n] - '0') * 10 + (s[n + 1] - '0') <= 26) {
            ans += alphacode(n + 2);
          }
        }
      }
      return ans;
    };
    cout << alphacode(0) << "\n";
  }
}