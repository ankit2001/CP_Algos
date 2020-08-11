#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Node{
public:
	ll data;
	Node* left;
	Node* right;
	Node(){
		this->data=0;
		left=NULL;
		right=NULL;
	}
	Node(ll d){
		this->data=d;
		left=NULL;
		right=NULL;
	}
};

void inorder(Node* x){
	if(x==NULL){
		return;
	}
	inorder(x->left);
	cout<<x->data<<" ";
	inorder(x->right);
}

Node* insert(Node* x,ll data){
	if(x==NULL){
		Node* new_node=new Node(data);
		return new_node;
	}
	if(data<x->data){
		x->left=insert(x->left,data);
	}
	else if(data>x->data){
		x->right=insert(x->right,data);
	}
	return x;
}

void search(Node* x,ll data){
	if(x==NULL){
		cout<<data<<" does not exist in bst"<<endl;
		return;
	}
	if(x->data==data){
		cout<<data<<" exist in bst"<<endl;
		return;
	}
	if(x->data>data){
		search(x->left,data);
	}
	else{
		search(x->right,data);
	}
}

Node* remove(Node* x,ll data){
	if(x==NULL) return x;
	if(x->data>data){
		x->left=remove(x->left,data);
		return x;
	}
	if(x->data<data){
	    x->right=remove(x->right,data);
	    return x;
	}
	if(x->left==NULL){
		Node* tmp=x->right;
		delete x;
		return tmp;
	}
	if(x->right==NULL){
		Node* tmp=x->left;
        delete x;
        return tmp;
	}
	Node* tmp=x->right;
	while(tmp!=NULL && tmp->left!=NULL){
		tmp=tmp->left;
	}
	x->data=tmp->data;
	x->right=remove(x->right,tmp->data);
	return x;
}

int main(){
	cout<<"Enter data in root node"<<endl;
	ll a;
	cin>>a;
	Node* root=NULL;
	root=insert(root,a);
	cout<<"Inset 5 nodes in bst"<<endl;
	ll b,c,d,e,f;
	cin>>b>>c>>d>>e>>f;
	root=insert(root,b);
	root=insert(root,c);
	root=insert(root,d);
	root=insert(root,e);
	root=insert(root,f);
    cout<<"After insertion inorder of bst will be"<<endl;
	inorder(root); cout<<endl;
	ll k;
	cout<<"Let's search a element in bst"<<endl;
	cin>>k;
	search(root,k);
	ll g,h;
	cout<<"Enter 2 element that you wana delete"<<endl;
	cin>>g>>h;
	root=remove(root,g);
	root=remove(root,h);
	cout<<"After deletion bst will be"<<endl;
	inorder(root); cout<<endl;
	return 0;
}