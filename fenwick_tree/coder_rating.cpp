#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define F first
#define S second

void update(ll index, vector<ll> &BIT){
	for(ll i=index;i<=100000;i+=i&(-i)){
		BIT[i]++;
	}
}

ll query(ll index, vector<ll> &BIT){
	ll count=0;
	for(ll i=index;i>0;i-=i&(-i)){
       count+=BIT[i];
	}
	return count;
}
int main(){
	vector<ll> BIT(100001,0);
	BIT[0]=0;
	ll n;
	cin>>n;
	vector<pair<pair<ll,ll>,ll>> v(n);
    for(ll i=0;i<n;i++){
    	ll x,y;
    	cin>>x>>y;
    	v[i]={{x,y},i};
    }
    ll ans[n];
    sort(v.begin(),v.end());

    for(ll i=0;i<n;i++){
    	ll end=i;
    	while(end<n and v[i].F.F==v[end].F.F and v[i].F.S==v[end].F.S){
    		end++;
    	}
    	for(ll j=i;j<end;j++){
    		ans[v[j].S]=query(v[j].F.S,BIT);
    	}
    	for(ll j=i;j<end;j++){
    		update(v[j].F.S,BIT);
    	}
    	i=end;
    	i--;
    }
    for(ll i=0;i<n;i++){
    	cout<<ans[i]<<endl;
    }
    return 0;
}