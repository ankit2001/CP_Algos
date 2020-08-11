#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main(){
	ll nodes;
	cout<<"Enter total number of nodes in graph : "<<endl;
	cin>>nodes;
	cout<<"Enter total number of edges in graph : "<<endl;
	ll edges;
	cin>>edges;
	ll graph[nodes+1][nodes+1];
	memset(graph,0,sizeof(graph));
    ll transpose_graph[nodes+1][nodes+1];
    memset(transpose_graph,0,sizeof(transpose_graph));
    cout<<"Enter edges as (a,b) as node a is directed towards node b : "<<endl;
    for(ll i=0;i<edges;i++){
    	ll a,b;
    	cin>>a>>b;
    	graph[a][b]=1;
    }
    cout<<"So the edges in graph is described below : "<<endl;
    for(ll i=1;i<=nodes;i++){
    	for(ll j=1;j<=nodes;j++){
    		if(graph[i][j]){
    			cout<<i<<" "<<j<<endl;
    			transpose_graph[j][i]=1;
    		}
    	}
    }
    cout<<"The transopose of above graph having edge structure is described below : "<<endl;
    for(ll i=1;i<=nodes;i++){
    	for(ll j=1;j<=nodes;j++){
    		if(transpose_graph[i][j]){
    			cout<<i<<" "<<j<<endl;
    		}
    	}
    }
    return 0;
}