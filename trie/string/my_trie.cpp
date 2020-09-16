#include<bits/stdc++.h>
using namespace std;

class Trie {
    public:
    Trie** child;
    bool is_end;
    Trie () {
        this -> child = new Trie*[26];
        this -> is_end = false;
        for (int i = 0; i < 26; i++) {
            this -> child[i] = nullptr;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        function<void(string, Trie*)> insert = [&] (string s, Trie* root) {
            Trie* curr = root;
            for (int i = 0; i < s.length(); i++) {
                int idx = s[i] - 'a';
                if (curr -> child[idx]) {
                    curr = curr -> child[idx];
                } else {
                    Trie* new_node = new Trie();
                    curr -> child[idx] = new_node;
                    curr = curr -> child[idx];
                }
            }
            curr -> is_end = true;
            return;
        };
        function<bool(string, Trie*)> search = [&] (string s, Trie* root) {
            Trie* curr = root;
            for (int i = 0; i < s.length(); i++) {
                int idx = s[i] - 'a';
                if (!(curr -> child[idx])) {
                    return false;
                }
                curr = curr -> child[idx];
            }
            if (curr -> is_end) {
                return true;
            }
            return false;
        };
        function<bool(Trie*)> is_node_ahead = [&] (Trie* root) {
            for (int i = 0; i < 26; i++) {
                if (root -> child[i]) {
                    return true;
                }
            }
            return false;
        };
        function<Trie*(string s, Trie*, int)> remove = [&] (string s, Trie* root, int idx) {
            if (root == nullptr) {
                return root;
            }
            if (idx = s.length()) {
                root -> is_end = false;
                if (!is_node_ahead(root)) {
                    delete root;
                    root = nullptr;
                }
                return root;
            }
            int p = s[idx] - 'a';
            root -> child[p] = remove(s, root -> child[p], idx + 1);
            if (!is_node_ahead(root) and !(root -> is_end)) {
                delete root;
                root = nullptr;
            }
            return root;
        };
        Trie* root = new Trie();
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                string s;
                cin >> s;
                insert(s, root);
            } else if (x == 2){
                string s;
                cin >> s;
                cout << search(s, root) << "\n";
            } else {
                string s;
                cin >> s;
                if (search(s, root)) {
                    root = remove(s, root, 0);
                }
            }
        }
    }
}
