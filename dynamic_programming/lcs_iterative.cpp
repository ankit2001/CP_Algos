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
    for(ll i = 0; i <= n; i++){
      dp[i][0] = 0;
    }
    for(ll i = 0; i <= m; i++){
      dp[0][i] = 0;
    }
    for(ll i = 1; i <= n; i++){
      for(ll j = 1; j <=m; j++){
        if(s1[n - i] == s2[m - j]){
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } 
        else{
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    cout << dp[n][m] << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    