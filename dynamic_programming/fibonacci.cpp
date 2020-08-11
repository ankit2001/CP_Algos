#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long dp[n + 1];
  bool vis[n + 1];
  memset(vis, false, sizeof(0));
  function<long long(int)> fibo = [&](int n) {
    auto &ans = dp[n];
    auto &seen = vis[n];
    if (!seen) {
      seen = true;
      if (n <= 1) {
        ans = n;
        return ans;
      }
      ans = fibo(n - 1) + fibo(n - 2);
    }
    return ans;
  };
  long long x = fibo(n);
  for (int i = 0; i < n; i++) {
    cout << dp[i] << "\n";
  }
}