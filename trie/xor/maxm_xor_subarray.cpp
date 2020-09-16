#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Trie{
public:
	Trie* left;
	Trie* right;
	Trie(){
		this->left=nullptr;
		this->right=nullptr;
	}
};

void insert(Trie* root, ll value){
	Trie* x=root;
	for(ll i=31;i>=0;i--){
		ll bit=((value>>i)&1);
		if(bit){
			if(!(x->right)){
				Trie* new_node=new Trie();
				x->right=new_node;
			}
			x=x->right;
		}
		else{
			if(!(x->left)){
				Trie* new_node=new Trie();
				x->left=new_node;
			}
			x=x->left;
		}
	}
}

ll query(Trie* root,ll value){
	Trie* x=root;
	ll ans=0;
	for(ll i=31;i>=0;i--){
		ll bit=((value>>i)&1);
		if(bit){
			if(x->left){
				ans+=(1<<i);
				x=x->left;
			}
			else{
				x=x->right;
			}
		}
		else{
			if(x->right){
				ans+=(1<<i);
				x=x->right;
			}
			else{
				x=x->left;
			}
		}
	}
	return ans;
}
int main(){
	ll n;
	cin>>n;
	ll arr[n];
	ll pref=0;
	Trie* root=new Trie();
	insert(root,0);
	ll maxi=-1;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		pref=pref^arr[i];
		insert(root,pref);
		maxi=max(maxi,query(root,pref));
	}
	cout<<maxi<<endl;
	return 0;
}