#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class PriorityQueue{
public:
	vector<ll> v;

	ll size(){
		return v.size();
	}

    bool empty(){
    	return v.size()==0;
    }

    ll getMax(){
    	if(v.size()==0){
    		cout<<"priority queue is empty"<<endl;
    		return 0;
    	}
    	return v[0];
    }

    void insert(ll d){
    	v.push_back(d);
    	ll c_index=v.size()-1;
    	while(1){
    		if(c_index<=0) break;
    		ll p_index=(c_index-1)/2;		
    		if(v[p_index]<v[c_index]){
    			swap(v[p_index],v[c_index]);
    		}
    		else break;
    		c_index=p_index;
    	}
    }

    ll removeMax(){
        if(v.size()==0){
        	cout<<"priority queue is empty"<<endl;
        	return 0;
        }
        ll ans=v[0];
        swap(v[0],v[size()-1]);
        v.pop_back();
        ll p_index=0;
        while(1){
        	if(p_index>=v.size()){
        		break;  
        	}
        	ll c_left_index=2*p_index+1;
        	ll c_right_index=2*p_index+2;
        	ll flag=0;
        	if(c_left_index<=v.size()-1 && v[c_left_index]>v[p_index]){
        		swap(v[c_left_index],v[p_index]);
        		flag=1;
        		p_index=c_left_index;
        	}
        	else if(c_right_index<=v.size()-1 && v[c_right_index]>v[p_index]){
        		swap(v[c_right_index],v[p_index]);
        		flag=1;
        		p_index=c_right_index;
        	}
        	if(flag==0){
        		break;
        	}
        }
        return ans;
    }
    void print(){
    	for(auto x: v){
    		cout<<x<<" ";
    	}
    	cout<<endl;
    }
};

int main(){
	PriorityQueue pq;
    cout<<"Enter 4 element in priority queue"<<endl;
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    pq.insert(a);
    pq.insert(b);
    pq.insert(c);
    pq.insert(d);
    cout<<"After insertion priority queue will be :"<<endl;
    pq.print();
    cout<<"Maximum element in priority queue is :"<<endl;
    cout<<pq.getMax()<<endl;
    cout<<"Size of priority queue is"<<endl;
    cout<<pq.size()<<endl;
    cout<<"Check priority queue is empty or not"<<endl;
    cout<<pq.empty()<<endl;
    cout<<"After removing maximum element, priority queue will be"<<endl;
    pq.removeMax();
    pq.print();
    return 0;
}