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

class query{
public:
  ll l, r, idx;
};

bool cmp(query a, query b){
  if(a.r == b.r){
    return a.l < b.l;
  }
  return a.r < b.r;
}

ll n, q;
vector<ll> last(1000000 + 1, 0);
vector<ll> arr(30000 + 1);
vector<ll> BIT(30000 + 1, 0);
query qs[200000 + 1];

void update(ll idx, ll value){
  for(ll i = idx; i <= n; i += i & -i){
    BIT[i] += value;
  }
}

ll find(ll idx){
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
  cout << PI << endl;
  for (ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    cin >> n;
    for(ll i = 1; i <= n; i++){
      cin >> arr[i];
    }
    cin >> q;
    for(ll i = 1; i <= q; i++){
      cin >> qs[i].l >> qs[i].r;
      qs[i].idx = i;
    }
    sort(qs + 1, qs + q + 1, cmp);
    ll ans[q + 1];
    ll k = 1;
    for(ll i = 1; i <= n; i++){
      if(k == q + 1){
        break;
      }
      if(!last[arr[i]]){
        update(i, 1);
        last[arr[i]] = i;
      }
      else{
        update(last[arr[i]], -1);
        update(i, 1);
        last[arr[i]] = i;
      }
      while(qs[k].r == i){
        ans[qs[k].idx] = find(i) - find(qs[k].l - 1);
        k++;
      }
    }
    for(ll i = 1; i <= q; i++){
      cout << ans[i] << endl;
    }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    