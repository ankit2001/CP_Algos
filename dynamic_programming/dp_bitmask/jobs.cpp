//Back to basics, always keep calm
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
ll solve(vector<vector<ll>> &cost, vector<ll> &dp, ll mask, ll n, ll p){
  if(p >= n){
    return 0;
  }
  if(dp[mask] != -1){
    return dp[mask];
  }
  ll ans = MAX;
  for(ll i = 0; i < n; i++){
    if(! (mask & (1 << i))){
      ans = min(ans, solve(cost, dp, mask | (1 << i), n, p + 1) + cost[p][i]);
    }
  }
  dp[mask]= ans;
  return ans;
}
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc=1;
  cin>>tc;
  for(ll tt=1;tt<=tc;tt++){
    cout << "Case "<<tt<<" :";
    ll n;
    cin >> n;
    vector<vector<ll>> cost(n,vector<ll>(n));
    for(ll i = 0;i < n; i++){
      for(ll j = 0;j < n; j++){
        cin >> cost[i][j];
      }
    }
    vector<ll> dp((1 << n), -1);
    cout << solve(cost, dp, 0ll, n, 0ll) << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}