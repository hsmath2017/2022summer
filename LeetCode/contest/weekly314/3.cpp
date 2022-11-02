#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string robotWithString(string s) {
        map<char,vector<int>> char2index;
        int n=s.length();
        for(int i=0;i<n;i++){
            char2index[s[i]].push_back(i);
        }
        int nowidx=0;
        stack<char> st;
        string ans;
        for (char c='a';c<='z';c++)
        {
            while(!st.empty()&&st.top()<=c){
                ans.push_back(st.top());
                st.pop();
            }
            for(auto v:char2index[c]){
                if(v>=nowidx){
                    for(int i=nowidx;i<=v;i++){
                        st.push(s[i]);
                    }
                    nowidx=v+1;
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};