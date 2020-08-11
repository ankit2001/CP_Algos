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
 
int main(){
  fastio();
 /* #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif*/
  ll tc = 1;
  //cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> pre(n + 1, vector<ll> (m + 1, 0));
    vector<vector<ll>> arr(n + 1, vector<ll> (m + 1, 0));
    for(ll i = 1; i <= n; i++){
      for(ll j = 1; j <= m; j++){
        cin >> arr[i][j];
      }
    }
    for(ll i = 1; i <= n; i++){
      ll sumi = 0;
      for(ll j = 1; j <= n; j++){
        sumi += arr[i][j];
        pre[i][j] = sumi;
      }
    }
    ll ans = MIN;
    for(ll l = 1; l <= m; l++){
      for(ll r = l; r <= m; r++){
        ll best_sum = MIN;
        ll max_sum = 0;
        for(ll i = 1; i <= n; i++){
          max_sum += pre[i][r] - pre[i][l - 1];
          if(best_sum < max_sum){
            best_sum = max_sum;
          }
          if(max_sum < 0){
            max_sum = 0;
          }
        }
        ans = max(ans, best_sum);
      }
    }
    cout << ans << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    