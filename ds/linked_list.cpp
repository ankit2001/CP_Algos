#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
class Node{
public:
	ll data;
	Node* nxt;
	Node(){
		this->data=0;
		this->nxt=NULL;
	}
	Node(ll d){
		this->data=d;
		this->nxt=NULL;
	}
};
Node* make_linked_list(){
	cout<<"Let's make a linked list :"<<endl;
    cout<<"Enter data in head node"<<endl;
    ll a;
    cin>>a;
    Node** temp;
	Node* head=new Node(a);
	temp=&head;
	string s;
	cout<<"Do you wana add more nodes ?('y' for yes)"<<endl;
	cin>>s;
	while(s=="y"){
	   cout<<"Enter data in node"<<endl;
	   ll el;
	   cin>>el;
       Node* new_node=new Node(el);
       (*temp)->nxt=new_node;
       temp=&((*temp)->nxt);
       cout<<"Do you wana add more nodes ?('y' for yes)"<<endl;
       cin>>s;
	}
	return head;
}
void insert(Node** head,ll *size){
	cout<<"Enter the position you wanna insert a new_node"<<endl;
	ll k;
	cin>>k;
    if(*size<k){
    	cout<<"OUT OF BOUNDS"<<endl;
    	return;
    }
    if(*size==k){
    	ll a;
    	cout<<"Enter the element you wana insert"<<endl;
    	cin>>a;
    	Node* new_node=new Node(a);
    	Node* x=new Node();
    	x=*head;
    	while(x->nxt!=NULL){
           x=x->nxt;
    	}
    	x->nxt=new_node;
    	(*size)++;
    	return ;
    }
    if(k==0){
    	ll a;
    	cout<<"Enter the element you wana insert "<<endl;
    	cin>>a;
    	Node* new_node=new Node(a);
    	new_node->nxt=(*head);
    	(*head)=new_node;
    	(*size)++;
    	return;
    }
    Node* x=new Node();
    x=*head;
    while(k!=1){
        x=x->nxt;
        k--;
    }
    ll a;
    cout<<"Enter the element you wana insert"<<endl;
    cin>>a;
    Node* new_node=new Node(a);
    new_node->nxt=x->nxt;
    x->nxt=new_node;
    (*size)++;
    return;
}

void remove(Node** head,ll *size){
	ll k;
	cout<<"Enter the position of node you wana delete"<<endl;
	cin>>k;
	if(*size<k+1){
		cout<<"OUT of Bounds"<<endl;
		return;
	}
	if(k==0){
		(*head)=(*head)->nxt;
		(*size)--;
		return;
	}
    if(k==(*size)-1){
    	Node* x;
        x=(*head);
        while(k!=1){
    	    x=x->nxt;
    	    k--;
        }
        x->nxt=NULL;
        (*size)--;
        return;
    }
    Node* x=new Node();
    x=*head;
    while(k!=1){
    	x=x->nxt;
    	k--;
    }
    x->nxt=(x->nxt)->nxt;
    (*size)--;
    return;
}

ll size(Node* x){
	ll count=0;
	while(x!=NULL){
		count++;
		x=x->nxt;
	}
	return count;
}
void print(Node* x){
	cout<<"Resulting linked list is :"<<endl;
	while(x!=NULL){
		cout<<x->data<<" ";
		x=x->nxt;
	}
	cout<<endl;
}
int main(){
   Node* head=new Node();
   head=make_linked_list();
   print(head);
   ll sz=size(head);
   for(ll i=0;i<3;i++){
      insert(&head,&sz);
      print(head);
   }
   cout<<"Size of linked list is"<<endl;
   cout<<size(head)<<endl;
   for(ll i=0;i<3;i++){
   	  remove(&head,&sz);
   	  print(head);
   }
   return 0;
}