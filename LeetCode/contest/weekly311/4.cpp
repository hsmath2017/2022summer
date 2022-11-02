#include<bits/stdc++.h>
using namespace std;
class Trie {
private:
    vector<Trie*> root;//存储节点
    int wordd;//存储是否为单词
    int score;
public:
    Trie(){
        root.resize(26);
        wordd=0;
        score=0;
    }
    ~Trie()=default;
    void insert(const string& word){
        Trie* node=this;
        for(auto& C:word){
            if(!node->root[C-'a']){
                Trie* tmp=new Trie;
                node->root[C-'a']=tmp;
            }
            node=node->root[C-'a'];
        }
        node->wordd++;
    }
    int check(const string& word){
        int ans=0;
        Trie* tmp=this;
        for(auto c:word){
            tmp=tmp->root[c-'a'];
            if(tmp){
                ans+=tmp->score;
            }
        }
        return ans;
    }
    static int getScore(Trie* TN){
        if(TN==nullptr){
            return 0;
        }
        if(TN->score){
            return TN->score;
        }
        int ans=0;
        ans+=TN->wordd;
        for(auto it:TN->root){
            ans=ans+getScore(it);
        }
        TN->score=ans;
        return ans;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root=new Trie;
        for(auto str:words){
            root->insert(str);
        }
        Trie::getScore(root);
        vector<int> ans(words.size());
        for(int i=0;i<words.size();i++){
            ans[i]=root->check(words[i]);
        }
        return ans;
    }
};