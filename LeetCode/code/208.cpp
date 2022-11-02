#include<bits/stdc++.h>
using namespace std;
class Trie {
private:
    vector<Trie*> trietree;
    bool isword;
public:
    Trie() {
        trietree.resize(26);
        isword=false;
    }
    
    void insert(string word) {
        Trie* root=this;
        for(auto c:word){
            if(!root->trietree[c-'a']){
                root->trietree[c-'a']=new Trie;
            }
            root=root->trietree[c-'a'];
        }
        root->isword=true;
    }
    
    bool search(string word) {
        Trie* root=this;
        for(auto c:word){
            if(!root->trietree[c-'a']){
                return false;
            }else{
                root=root->trietree[c-'a'];
            }
        }
        return root->isword;
    }
    
    bool startsWith(string prefix) {
        Trie* root=this;
        for(auto c:prefix){
            if(!root->trietree[c-'a']){
                return false;
            }else{
                root=root->trietree[c-'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */