#include <bits/stdc++.h>
using namespace std;
int n;
string s;

struct Node{
    int child[26];
    bool is_end;
};
vector<Node> trie;

int create(){
    Node new_node;
    new_node.is_end = false;

    for (int i = 0; i < 26; ++i) new_node.child[i] = -1;

    trie.push_back(new_node);
    return trie.size()-1;
}

bool insert(string w){
    int id = 0;
    bool is_new = false, passed_end = false;

    for (char c : w){
        int charid = c - 'a';

        if (trie[id].child[charid] == -1){
            int new_id = create();
            trie[id].child[charid] = new_id;
            is_new = true;
        }

        id = trie[id].child[charid];

        if (trie[id].is_end) passed_end = true;
    }

    trie[id].is_end = true;

    return (!is_new || passed_end);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
k