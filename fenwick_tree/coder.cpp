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

class coder{
public:
  ll x, y, idx;
};
ll n;
coder arr[300000 + 1];
vector<ll> BIT(300000 + 1, 0);

bool cmp (coder a, coder b){
  if(a.x == b.x){
    return a.y < b.y;
  }
  return a.x < b.x;
}

void update(ll idx, ll value){
  for(ll i = idx; i <= 300000; i += i & -i){
    BIT[i] += value;
  }
}

ll query(ll idx){
  ll count = 0;
  for(ll i = idx; i > 0; i -= i & -i){
    count += BIT[i];
  }
  return count;
}
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
  //cin >> tc;
  for (ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    cin >> n;
    for(ll i = 0; i < n; i++){
      cin >> arr[i].x >> arr[i].y;
      arr[i].idx = i;
    }
    ll ans[n];
    sort(arr, arr + n, cmp);
    ll i = 0;
    while(1){
      if(i >= n){
        break;
      }
      ll idx = i;
      while(i < n and arr[i].y == arr[idx].y and arr[i].x == arr[idx].x){
        i++;
      }
      for(ll j = idx; j < i; j++){
        ans[arr[j].idx] = query(arr[j].y);
      }
      for(ll j = idx; j < i; j++){
        update(arr[j].y, 1ll);
      }
    }
    for(ll i = 0; i < n; i++){
      cout << ans[i] << endl;
    }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    