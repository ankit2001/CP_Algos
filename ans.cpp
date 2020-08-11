//I give up
#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long  power(long  x,long n){
  if(n == 0)
      return 1;
  else if(n % 2==0)       
      return power(((x % mod)*(x % mod)) %mod , n/2);
  else                            
      return ((x % mod)*(power(((x % mod)*(x % mod) % mod) % mod, (n-1)/2) % mod)) % mod;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        long long n;
        cin >> n;
        long long ans = 1;
        long long x = (power(2, n - 1)) % mod;
        for (int i = 1; i <= n; i++) {
            ans = ((ans % mod) * (i % mod)) % mod;
        }
        cout << (ans - x + mod) % mod << "\n";
    }
    return 0;
}
