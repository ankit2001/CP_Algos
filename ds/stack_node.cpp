#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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
	Stack<ll> s;
	ll el;
	cout << "Enter element you want to push " << endl;
	cin >> el;
	s.push(el);
	cout << "After push operation elements in stack are " << endl;
	s.print();
	cout << "Size of stack is" << endl;
	cout << s.length() << endl;
	ll a, b, c;
	cout << "Enter 3 elements for pushing in stack" << endl;
	cin >> a >> b >> c;
	s.push(a);
	s.push(b);
	s.push(c);
	cout << "After push operation elements in stack are " << endl;
	s.print();
	cout << "Top element is stack is " << endl;
	cout << s.top() << endl;;
	cout << "After the pop operation elements in stack are " << endl;
	s.pop();
	s.print();
	cout << "Check is empty " << endl;
	cout << s.empty() << endl;
}