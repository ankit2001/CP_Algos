#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void update(ll index, ll value, vector<ll> &BIT){
	for(ll i=index;i<=BIT.size()-1;i+=(i&(-i))){
		BIT[i]+=value;
	}
}

ll query(ll index,vector<ll> &BIT){
	ll sum=0;
	for(ll i=index;i>0;i-=(i&(-i))){
       sum+=BIT[i];
	}
	return sum;
}

int main(){
	ll n;
	cin>>n;
	vector<ll> BIT(n+1);
	BIT[0]=1;
	vector<ll> arr(n+1);
	for(ll i=1;i<=n;i++){
       cin>>arr[i];
       update(i,arr[i],BIT);
	}
	for(ll i=0;i<=n;i++){
		cout<<query(i,BIT)<<" ";
	}
	cout<<endl;
	return 0;
}