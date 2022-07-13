#include<bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet {
private:
    map<int,bool> poped;
    int now_traverse;
    priority_queue<int> s;
public:
    SmallestInfiniteSet() {
        now_traverse=1;
    }
    
    int popSmallest() {
        if(s.empty()){
            poped[now_traverse]=true;
            return now_traverse++;
        }else{
            int x=s.top();
            poped[x]=true;
            s.pop();
            return x;
        }
    }
    
    void addBack(int num) {
        if(poped[num]==true){
            poped[num]=false;
            s.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */