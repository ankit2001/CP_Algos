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
 
ll solve(vector<vector<ll>> &dp, vector<vector<ll>> &vis, vector<vector<ll>> &cost,ll i, ll j, ll r, ll c){
  auto &ans = dp[i][j];
  auto &seen = vis[i][j];
  if(!seen){
    seen = true;
    if(i == r - 1 and j == c - 1){
      ans = 1;
      return ans;
    }
    ll mini = MAX;
    if(i + 1 <= r - 1){
      mini = min(mini, solve(dp, vis, cost, i + 1, j, r, c));
    }
    if(j + 1 <= c - 1){
      mini = min(mini, solve(dp, vis, cost, i, j + 1, r, c));
    }
    ans = mini - cost[i][j];
    if(ans <= 0){
      ans = 1;
    }
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
  for(ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    ll r, c;
    cin >> r >> c;
    vector<vector<ll>> cost(r + 1, vector<ll>(c + 1, 0));
    vector<vector<ll>> dp(r + 1, vector<ll>(c + 1, 0));
    vector<vector<ll>> vis(r + 1, vector<ll>(c + 1, false));

    for(ll i = 0; i < r; i++){
      for(ll j = 0; j < c; j++){
        cin >> cost[i][j];
      }
    }
    cout << solve(dp, vis, cost, 0, 0, r, c) << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    