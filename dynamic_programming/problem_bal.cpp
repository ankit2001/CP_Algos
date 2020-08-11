//Keep calm and admire
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
 
ll MAX = 1e18;
ll MOD = 1000000007;
ll MIN = -1e17;

ll solve(vector<vector<vector<ll>>> &dp, vector<vector<vector<ll>>> &vis, string s1, string s2, ll n, ll m, ll k){
  auto &ans = dp[n][m][k];
  auto &seen = vis[n][m][k];
  if(!seen){
    seen = true;
    if((n == 0 or m == 0) and k != 0){
      ans = MIN;
    }
    else if(k == 0){
      ans = 0;
    }
    else{
      if(s1[n - 1] == s2[m - 1]){
        ans = max(max(int(s1[n - 1]) + solve(dp, vis, s1, s2, n - 1, m - 1, k - 1), solve(dp, vis, s1, s2, n - 1, m, k)),solve(dp, vis, s1, s2, n, m - 1, k));
      }
      else{
        ans = max(solve(dp, vis, s1, s2, n - 1, m, k), solve(dp, vis, s1, s2, n, m - 1, k));
      }
    }
  }
  return ans ;
}
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
  cin >> tc;
  for (ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    string s1, s2;
    cin >> s1 >> s2;
    ll k;
    cin >> k;
    ll n = s1.length(), m = s2.length();
    vector<vector<vector<ll>>> dp (n + 1, vector<vector<ll>> (m + 1, vector<ll> (k + 1, 0)));
    vector<vector<vector<ll>>> vis(n + 1, vector<vector<ll>> (m + 1, vector<ll> (k + 1, 0)));
    if(solve(dp, vis, s1, s2, n, m, k) > 0){
      cout << solve(dp, vis, s1, s2, n, m, k) << endl;
    }
    else cout << 0 << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    