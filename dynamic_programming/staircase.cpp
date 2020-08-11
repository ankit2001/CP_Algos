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

ll solve(vector<ll> &dp, vector<ll> &vis, ll n){
  auto &ans = dp[n];
  auto &seen = vis[n];
  if(!seen){
    seen = true;
    if(n == 1){
      ans = 1;
      return ans;
    }
    if(n == 2){
      ans = 2;
      return ans;
    }
    if(n == 3){
      ans = 4;
      return ans;
    }
    ans = solve(dp, vis, n - 1) + solve(dp, vis, n - 2) + solve(dp, vis, n - 3);
  }
  return ans;
}
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
  cin >> tc;
  vector<ll> dp(100 + 1, 0);
  vector<ll> vis(100 + 1, false);
  solve(dp, vis, 100);
  for(ll tt = 1; tt <= tc; tt++){
   // cout << "Case "<<tt<<" :";
    ll n; 
    cin >> n;
    cout << dp[n] << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    