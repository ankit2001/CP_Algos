#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T>
class Node{
public:
    T data;
    Node<T>* nxt;
    Node(){
        this -> data = 0;
        this -> nxt = NULL;
    }
    Node(T d){
        this -> data = d;
        this -> nxt = NULL;
    }
};

template<typename T>
class Stack{
public:

    Node<T>* last;
    ll size;

    Stack(){
        this -> size = 0;
        last = NULL;
    }

    ll length(){
        return size;
    }

    bool empty(){
        return size == 0;
    }

    T top(){
        if(size == 0){
            cout << "No element is present in stack" << endl;
            return 0;
        }
        return last -> data;
    }

    void push(ll d){
        Node<T>* new_node = new Node<T>(d);
        if(size == 0){
            last = new_node;
            size++;
            return;
        }
        new_node -> nxt = last;
        last = new_node;
        size++;
    }

    T pop(){
        if(size == 0){
            cout << "No element is present is stack " << endl;
            return 0;
        }
        Node<T>* tmp = last;
        T ans = last -> data;
        last = last -> nxt;
        delete tmp;
        size--;
        return ans;
    }

    void print(){
        Node<T>* x = last;
        cout << "Elements from last to first " << endl;
        while(x != NULL){
            cout << x -> data << " ";
            x = x -> nxt;
        }
        cout << endl;
    }
};
int main(){
	cout << "Enter the postfix expression : (There should be space between every element of exp othewise it will give segmentation fault)" << endl;
    string post;
    getline(cin, post);
    Stack<ll> st;
    for(ll i = 0;i < post.length(); i++){
    	if(post[i] == ' '){
    		continue;
    	}
    	else if(isdigit(post[i])){
            ll num=0;  
            while(isdigit(post[i])){
                num = num * 10 + (ll)(post[i] - '0');  
                i++;  
            }  
            i--;  
            st.push(num); 
        }
    	else{
    		ll a = st.top();
    		ll poped = st.pop();
    		ll b = st.top();
    		poped = st.pop();
    		if(post[i] == '+'){
    			st.push(b + a);
    		}
    		else if(post[i] == '-'){
    			st.push(b - a);
    		}
    		else if(post[i] == '*'){
    			st.push(b * a);
    		}
    		else if(post[i] == '/'){
    			st.push(b / a);
    		}
    		else if(post[i] == '|'){
    			st.push(b | a);
    		}
    		else if(post[i] == '&'){
    			st.push(b & a);
    		}
    		else if(post[i] == '^'){
    			st.push(b ^ a);
    		}
    		else if(post[i] == '%'){
    			st.push(b % a);
    		}
    	}
    }
    cout << "After solving the expression, final answer is : " << endl;
    cout << st.top() << endl;
    return 0;
}