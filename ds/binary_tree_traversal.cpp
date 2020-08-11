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

void preorder(Node* x){
	if(x==NULL){
		return;
	}
	cout<<x->data<<" ";
	preorder(x->left);
	preorder(x->right);
}

void postorder(Node* x){
	if(x==NULL){
		return;
	}
	postorder(x->left);
	postorder(x->right);
	cout<<x->data<<" ";
}

void inorder(Node* x){
	if(x==NULL){
		return;
	}
	inorder(x->left);
	cout<<x->data<<" ";
	inorder(x->right);
}  


int main(){
	cout<<"Let's make a binary tree"<<endl;
	cout<<"Enter root node"<<endl;
	ll a;
	cin>>a;
	Node* root=new Node(a);
	cout<<"Enter l,r of "<<a<<endl;
	ll l,r;
	cin>>l>>r;
	root->left=new Node(l);
	root->right=new Node(r);
	cout<<"Enter l,r of "<<root->left->data<<endl;
	ll p,q;
	cin>>p>>q;
	root->left->left=new Node(p);
	root->left->right=new Node(q);
	ll v,m;
	cout<<"Enter l,r of "<<root->right->data<<endl;
	cin>>v>>m;
	root->right->left=new Node(v);
	root->right->right=new Node(m);
	cout<<"Preorder traversal of tree"<<endl;
	preorder(root); cout<<endl;
    cout<<"Postorder traversal of tree"<<endl;
    postorder(root); cout<<endl;
    cout<<"Inorder traversal of tree"<<endl;
    inorder(root); cout<<endl;
    return 0;
}