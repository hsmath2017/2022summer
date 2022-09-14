#include<bits/stdc++.h>
using namespace std;
class NumberContainers {
public:
    using st=set<int>;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        Container[number].insert(index);
        if(nums[index]==0){
            nums[index]=number;
        }else{
            int d=nums[index];
            Container[number].erase(d);
            nums[index]=number;
        }
    }
    
    int find(int number) {
        if(Container[number].size()==0){
            return -1;
        }else{
            return *Container[number].begin();
        }
    }
private:
    map<int,st> Container;
    map<int,int> nums;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */