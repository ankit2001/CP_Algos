#//Keep calm and admire
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

class store{
public:
  ll ans;
};

ll n, q;
vector<store> st(4 * (1 << 17) + 1);
vector<ll> arr((1 << 17) + 1);

store init(ll value){
  store data;
  data.ans = value;
  return data;
}
store merge1(store l, store r){
  store data;
  if(int(log2(n)) % 2 == 0) data.ans = l.ans | r.ans;
  else data.ans = l.ans ^ r.ans;
  return data;
}
store merge2(store l, store r){
  store data;
  if(int(log2(n)) % 2 == 0) data.ans = l.ans ^ r.ans;
  else data.ans = l.ans | r.ans;
  return data;
}
void build(ll lo, ll hi, ll v){
  if(lo == hi){
    st[v] = init(arr[lo]);
    return ;
  }
  ll mid = lo + hi >> 1;
  build(lo, mid, 2 * v + 1);
  build(mid + 1, hi, 2 * v + 2);
  if(int(log2(n / (hi - lo + 1))) % 2 == 1) st[v] = merge1(st[2 * v + 1], st[2 * v + 2]);
  else st[v] = merge2(st[2 * v + 1], st[2 * v + 2]);
}

void update(ll lo, ll hi, ll idx, ll value, ll v){
  if(lo == hi){
    arr[lo] = value;
    st[v] = init(value);
    return;
  }
  ll mid = lo + hi >> 1;
  if(mid >= idx){
    update(lo, mid, idx, value, 2 * v + 1);
  }
  else{
    update(mid + 1, hi, idx, value, 2 * v + 2);
  }
  if(int(log2(n / (hi - lo + 1))) % 2 == 1) st[v] = merge1(st[2 * v + 1], st[2 * v + 2]);
  else st[v] = merge2(st[2 * v + 1], st[2 * v + 2]);
}

store query(ll lo, ll hi, ll l, ll r, ll v){
  if(lo > r or hi < l){
    return init(0ll);
  }
  if(lo >= l and hi <= r){
    return st[v];
  }
  ll mid = lo + hi >> 1;
  if(int(log2(n / (hi - lo + 1))) % 2 == 1) return merge1(st[2 * v + 1], st[2 * v + 2]);
  else return merge2(st[2 * v + 1], st[2 * v + 2]);
}
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
 // cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    cin >> n >> q;
    n = (1 << n);
    for(ll i = 0; i < n; i++){
      cin >> arr[i];
    }
    build(0, n - 1, 0);
    for(ll i = 0; i < q; i++){
      ll idx, value;
      cin >> idx >> value;
      idx--;
      update(0, n - 1, idx, value, 0);
      cout << query(0, n - 1, 0, n - 1, 0).ans << endl;
    }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    