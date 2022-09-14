#include<bits/stdc++.h>
using namespace std;
class SORTracker {
public:
    using en=pair<int,string>;
    priority_queue<en,vector<en>,less<en>> front;
    priority_queue<en,vector<en>,greater<en>> tail;
    int checknum;
    SORTracker() {
        checknum=1;
    }
    
    void add(string name, int score) {
        en pair{-score,name};
        if(front.size()<checknum){
            front.push(pair);
        }else{
            auto t=front.top();
            if(pair>t){
                tail.push(pair);
            }else{
                front.pop();
                tail.push(t);
                front.push(pair);
            }
        }
    }
    
    string get() {
        auto t=front.top();
        checknum++;
        if(!tail.empty()){
            auto x=tail.top();
            front.push(x);
            tail.pop();
        }
        return t.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */