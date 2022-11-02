#include<bits/stdc++.h>
using namespace std;
class TopVotedCandidate {
public:
    using pii=pair<int,int>;
    set<pii,std::greater<pii>> S;
    int nowidx=0;
    vector<int> time;
    vector<int> person;
    map<pii,int> pair2index;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        person=persons;
        time=times;
    }
    
    int q(int t) {
        for(nowidx;nowidx<time.size()&&time[nowidx]<=t;nowidx++){
            
        }
        nowidx--;

    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */