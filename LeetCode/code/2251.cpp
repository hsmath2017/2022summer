#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binary_find(int p,const vector<int>& index,int start,int end){
        if(p>index[0]){
            return -1;
        }
        if(start==end){
            return start;
        }
        int mid=(start+end)/2;
        if(p>index[mid]){
            return binary_find(p,index,0,mid);
        }else{
            return binary_find(p,index,mid+1,end);
        }
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int,int> diff;
        for(auto v:flowers){
            diff[v[0]]++;
            diff[v[1]+1]--;
        }
        map<int,int> sum;
        vector<int> index;
        int now=0;
        for(auto it:diff){
            now+=it.second;
            sum[it.first]=now;
            index.push_back(it.first);
        }
        vector<int> ans;
        for(auto p:persons){
            int id=binary_find(p,index,0,index.size()-1);
            if(id==-1){
                ans.push_back(0);
                continue;
            }
            ans.push_back(sum[id]);
        }
        return ans;
    }
};