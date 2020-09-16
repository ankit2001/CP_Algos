#include<bits/stdc++.h>
using namespace std;

class Trie {
	public:
	Trie* left;
	Trie* right;
	Trie() {
		this -> left = nullptr;
		this -> right = nullptr;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	//cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Trie* root = new Trie();
		auto insert = [&] (Trie* head, int val) {
			Trie* x = head;
			for (int i = 31; i >= 0; i--) {
				if ((val >> i) & 1) {
					if ((x -> right) == nullptr) {
						Trie* new_node = new Trie();
						x -> right = new_node;
					}
					x = x -> right;
				} else {
					if ((x -> left) == nullptr) {
						Trie* new_node = new Trie();
						x -> left = new_node;
					}
					x = x -> left;
				}
			}
		};
		for (int i = 0; i < n; i++) {
			insert(root, arr[i]);
		}
		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {
			int p = 0;
			Trie* x = root;
			for (int j = 31; j >= 0; j--) {
				if ((arr[i] >> j) & 1) {
					if ((x -> left) != nullptr) {
						x = x -> left;
						p += (1 << j);
					} else {
						x = x -> right;
					}
				} else {
					if ((x -> right) != nullptr) {
						x = x -> right;
						p += (1 << j);
					} else {
						x = x -> left;
					}
				}
				ans = max(ans, p);
			}
		}
		cout << ans;
	}
}	