#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	cout<<"Enter total number nodes in graph"<<endl;
	ll nodes;
	cin>>nodes;
	cout<<"Enter total numbert of edges in a graph"<<endl;
	ll edges;
	cin>>edges;
	vector<ll> graph[nodes+1];
	cout<<"Enter edges as (a,b) as node a is directed towards node b : "<<endl;
	vector<ll> transpose_graph[nodes+1];
	for(ll i=0;i<edges;i++){
		ll a,b;
		cin>>a>>b;
        graph[a].push_back(b);
	}
	cout<<"So the edges in graph is described below : "<<endl;
	for(ll i=1;i<=nodes;i++){
		for(auto x: graph[i]){
			cout<<i<<" "<<x<<endl;
			transpose_graph[x].push_back(i);
		}
	}
	cout<<"The transopose of above graph having edge structure is described below : "<<endl;
	for(ll i=1;i<=nodes;i++){
		for(auto x: transpose_graph[i]){
			cout<<i<<" "<<x<<endl;
		}
	}
	return 0;
}