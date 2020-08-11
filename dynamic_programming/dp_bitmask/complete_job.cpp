//Keep calm and admire
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()

ll MAX = 1e18;
ll MIN = -1e17;
ll MOD = 1e9 + 7;
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
  //cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll> (n, 0));
    vector<long long> dp((1 << n), 0);
    vector<ll> vis((1 << n),false);
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    }
    function<long long(ll, ll, ll)> solve = [&](ll p, ll mask, ll n){
      if(p >= n){
        return 1ll;
      }
      auto &ans = dp[mask];
      auto &seen = vis[mask];
      if(!seen){
        seen = true;
        ans = 0ll;
        for(ll i = 0; i < n; i++){
          if(!(mask & (1 << i)) and arr[p][i] == 1){
            ans += solve(p + 1, mask | (1 << i), n);
          }
        }
      }
      return ans;
    };
    cout << solve(0, 0, n) << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    