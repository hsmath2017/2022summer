#include<bits/stdc++.h>
using namespace std;
class LUPrefix {
private:
    vector<bool> avail;
    int pointer;
public:
    LUPrefix(int n) {
        pointer=0;
        avail.resize(n+1);
    }
    
    void upload(int video) {
        avail[video]=true;
    }
    
    int longest() {
        while(1){
            if(pointer+1<avail.size()&&avail[pointer+1]==true){
                pointer++;
            }else{
                break;
            }
        }
        return pointer;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */