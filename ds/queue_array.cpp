#include<bits/stdc++.h>
#define ll long long int
using namespace std;

template<typename T>
class Queue{
public:
	T *data;
    ll max_size;
    ll size;
    ll front_index,back_index;
    Queue(ll array_size){
    	data=new T[array_size];
    	this->max_size=array_size;
    	this->size=0;
    	this->front_index=-1;
    	this->back_index=0;
    }
    ll length(){
    	return size;
    }

    bool empty(){
    	return size==0;
    }

    T top(){
    	if(size==0){
    		cout<<"No element is present in queue :"<<endl;
    		return 0;
    	}
    	return data[front_index];
    }

    void push(T d){
    	if(size==max_size){
    		cout<<"Overflow occur "<<endl;
    		return ;
    	}
    	if(front_index=-1){
    		front_index=0;
    	}
    	data[back_index]=d;
    	back_index=(back_index+1)%max_size;
    	size++;
    }

    T pop(){
    	if(size==0){
    		cout<<"No element is present in queue :"<<endl;
    		return 0;
    	}
    	T ans=data[front_index];
    	front_index=(front_index+1)%max_size;
    	size--;
    	if(size==0){
    		front_index=-1;
    		back_index=0;
    	}
    	return ans;
    }

    void print(){
    	ll x=size,index=front_index;
    	while(x!=0){
    		cout<<data[index]<<" ";
    		index=(index+1)%max_size;
    		x--;
    	}
    	cout<<endl;
    }

};

int main(){
	cout<<"Enter capacity of queue you wana make :"<<endl;
	ll cap;
	cin>>cap;
	Queue<ll> q(cap);
	ll el;
	cout<<"Enter element you wana push to queue :"<<endl;
    cin>>el;
    q.push(el);
    cout<<"After push operation elements in queue are :"<<endl;
    q.print();
    cout<<"Size of queue is"<<endl;
    cout<<q.length()<<endl;
    ll a, b;
    cout<<"Enter 2 elements for pushing in queue "<<endl;
    cin>>a>>b;
    q.push(a);
    q.push(b);
    cout<<"After push operation elements in queue are :"<<endl;
    q.print();
    cout << "check top element in queue" << endl;
    cout << q.top() << endl;
    cout<<"After pop operation elements in queue are :"<<endl;
    q.pop();
    q.print();
    cout<<"Check is empty :"<<endl;
    cout<<q.empty()<<endl;
    return 0;
}