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

ll solve(vector<vector<ll>> &dp, vector<vector<ll>> &vis, string s1, string s2, ll n, ll m){
  ll &ans = dp[n][m];
  ll &seen = vis[n][m];
  if(!seen){
    seen = true;
    if(n == 0){
      ans = m;
    }
    else if(m == 0){
      ans = n;
    }
    else if(s1[n - 1] == s2[m - 1]){
      ans = solve(dp, vis, s1, s2, n - 1, m - 1);
    }
    else{
      ans = 1 + min(solve(dp, vis, s1, s2, n - 1, m - 1),min(solve(dp, vis, s1, s2, n - 1, m), solve(dp, vis, s1, s2, n, m - 1)));
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
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    ll n = s1.length(), m = s2.length();
    vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));
    vector<vector<ll>> vis(n + 1, vector<ll> (m + 1, false));
    cout << solve(dp, vis, s1, s2, n, m) << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    