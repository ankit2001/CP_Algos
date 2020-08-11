#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define F first
#define S second 
bool cmp(pair<pair<ll,ll>,ll> p1, pair<pair<ll,ll>,ll> p2){
	return p1.F.S < p2.F.S;
}
void update(ll index, ll value, vector<ll> &BIT){
	for(ll i=index;i<BIT.size();i+=(i&(-i))){
        BIT[i]+=value;
	}
}
ll query(ll index, vector<ll> &BIT){
	ll count=0;
	for(ll i=index;i>0;i-=(i&(-i))){
		count+=BIT[i];
	}
	return count;
}
int main(){
	ll n;
	cin>>n;
	vector<ll> arr(n+1,0);
	vector<ll> BIT(n+1,0);
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll q;
	cin>>q;
	vector<pair<pair<ll,ll>,ll>> queries(q);
	vector<ll> ans(q);
	ll p=0;
	for(ll i=0;i<q;i++){
		ll l,r;
		cin>>l>>r;
        queries[i]={{l,r},i};
	}
	sort(queries.begin(),queries.end(),cmp);
	unordered_map<ll,ll> mapi;
    for(ll i=1;i<=n;i++){
    	if(mapi[arr[i]]!=0){
    		update(mapi[arr[i]],-1,BIT);
    	}
    	mapi[arr[i]]=i;
    	update(i,1,BIT);
    	while(p<q and queries[p].F.S == i){
    		ans[queries[p].S]=query(i,BIT)-query(queries[p].F.F-1,BIT);
    		p++;
    	}
    }
    for(ll i=0;i<q;i++){
    	cout<<ans[i]<<endl;
    }

}