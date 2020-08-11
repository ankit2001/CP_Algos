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
    ll arr[n];
    for(ll i = 0; i < n; i++){
      cin >> arr[i];
    }
    ll sub[(1 << n)];
    for(ll i = 0; i < (1 << n); i++){
      ll sum = 0;
      for(ll j = 0; j < n; j++){
        if(i & (1 << j)){
          sum += arr[j];
        }
      }
      sub[i] = sum;
    }
    for(ll i = 0; i < (1 << n); i++){
    cout << sub[i] << endl;
  }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    