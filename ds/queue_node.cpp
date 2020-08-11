#include<bits/stdc++.h>
#define ll long long int
using namespace std;

template<typename T>
class Node{
public:
	T data;
	Node<T>* nxt;
	Node(){
		this->data=0;
		this->nxt=NULL;
	}
	Node(T d){
		this->data=d;
		this->nxt=NULL;
	}
};

template<typename T>
class Queue{
public:
	Node<T> *front;
	Node<T> *back;
	ll size;

	Queue(){
		front=NULL;
		back=NULL;
		this->size=0;
	}

    ll length(){
    	return size;
    }

    bool empty(){
    	return size==0;
    }

    T top(){
    	if(size==0){
    		cout<<"No element is present in queue"<<endl;
    	}
    	return front->data;
    }

    void push(ll d){
    	Node<T>* new_node=new Node<T>(d);
    	if(size==0){
           front=new_node;
           back=new_node;
           size++;
           return;
    	}
    	back->nxt=new_node;
    	back=back->nxt;
    	size++;
    }

    T pop(){
    	if(size==0){
    		cout<<"No element is present is queue :"<<endl;
    		return 0;
    	}
    	Node<T>* tmp=front;
        T ans=front->data;
        front=front->nxt;
        delete tmp;
        size--;
        return ans;
    }

    void print(){
    	Node<T>* x=front;
    	while(x!=NULL){
    		cout<<x->data<<" ";
    		x=x->nxt;
    	}
    	cout<<endl;
    }
};
int main(){
	Queue<ll> q;
	ll el;
	cout<<"Enter element you wana push to queue :"<<endl;
    cin>>el;
    q.push(el);
    cout<<"After push operation elements in queue are :"<<endl;
    q.print();
    cout<<"Size of queue is"<<endl;
    cout<<q.length()<<endl;
    ll a,b,c;
    cout<<"Enter 3 elements for pushing in queue "<<endl;
    cin>>a>>b>>c;
    q.push(a);
    q.push(b);
    q.push(c);
    cout<<"After push operation elements in queue are :"<<endl;
    q.print();
    cout << "Top element in queue is" << endl;
    cout << q.top() << endl;
    cout<<"After pop operation elements in queue are :"<<endl;
    q.pop();
    q.print();
    cout<<"Check is empty :"<<endl;
    cout<<q.empty()<<endl;
    return 0;
}