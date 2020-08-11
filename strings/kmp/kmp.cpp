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
ll MIN = -1e17;

vector<ll> prefix_function(string s){
  ll n = s.length(), border = 0;
  vector<ll> v(n, 0);
  for(ll i = 1; i <= n; i++){
    while(border > 0 and s[i] != s[border]){
      border = v[border - 1];
    }
    if(s[border] == s[i]){
      border += 1;
    }
    else border = 0;
    v[i] = border;
  }
  return v;
}

vector<ll> kmp(string s, string pat){
  ll n = s.length(), m = pat.length();
  vector<ll> pre = prefix_function(s);
  vector<ll> ans;
  for(ll i = m + 1; i < n; i++){
    if(pre[i] == m){
      ans.pb(i - 2 * m);
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
  //cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    string pat, text;
    cin >> pat >> text;
    string s = pat + "#" + text;
    vector<ll> ans = kmp(s, pat);
    for(auto x : ans){
      cout << x << " ";
    }
    cout << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    