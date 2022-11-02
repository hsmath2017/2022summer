#include<bits/stdc++.h>
using namespace std;
class DinnerPlates {
private:
    const int maxPlate=2e5;
    map<int,stack<int>> platestacks;
    int capacity;
    priority_queue<int,vector<int>,std::greater<int>> non_full;
    set<int,std::greater<int>> non_empty;
public:
    DinnerPlates(int capacity) {
        this->capacity=capacity;
        for(int i=0;i<maxPlate;i++){
            non_full.push(i);
        }
    }
    
    void push(int val) {
        int id=non_full.top();
        platestacks[id].push(val);
        if(platestacks[id].size()==capacity){
            non_full.pop();
        }
        non_empty.insert(id);
    }
    
    int pop() {
        if(non_empty.size()==0){
            return -1;
        }
        int id=*non_empty.begin();
        int val=platestacks[id].top();
        platestacks[id].pop();
        if(platestacks[id].size()==0){
            non_empty.erase(id);
        }
        return val;
    }
    
    int popAtStack(int index) {
        if(platestacks[index].size()==capacity){
            non_full.push(index);
        }
        if(platestacks[index].size()==0){
            return -1;
        }
        int val=platestacks[index].top();
        platestacks[index].pop();
        if(platestacks[index].size()==0){
            non_empty.erase(index);
        }
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */