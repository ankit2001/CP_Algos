#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Node{
public:
	ll data;
	Node* nxt;
    Node(ll d){
    	this->data=d;
    	nxt=NULL;
    }
};
int main(){
	Node *head=new Node(8);
	Node *d1=new Node(3);
	head->nxt=&d1;
	
}