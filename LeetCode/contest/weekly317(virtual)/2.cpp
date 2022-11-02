#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,vector<int>> createids;
        map<string,int> popularity;
        int n=creators.size();
        for(int i=0;i<n;i++){
            popularity[creators[i]]+=views[i];
            createids[creators[i]].push_back(i);
        }
        vector<vector<string>> ans(2);
        vector<string> thecreator;
        int nowmax=-1;
        for(auto it:popularity){
            if(it.second>nowmax){
                nowmax=it.second;
                thecreator.clear();
                thecreator.push_back(it.first);
            }else if(it.second==nowmax){
                thecreator.push_back(it.first);
            }
        }
        sort(thecreator.begin(),thecreator.end());
        ans[0]=thecreator;
        for(auto s:thecreator){
            int id=-1;
            int nowm=-1;
            auto vec=createids[s];
            for(auto c:vec){
                if(views[c]>nowm){
                    id=c;
                    nowm=views[c];
                }else if(views[c]==nowm){
                    if(ids[c]<ids[id]){
                        id=c;
                    }
                }
            }
            ans[1].push_back(ids[id]);
        }
        vector<vector<string>> res;
        int t=ans[0].size();
        for(int i=0;i<t;i++){
            res.push_back({ans[0][i],ans[1][i]});
        }
        return res;
    }
};