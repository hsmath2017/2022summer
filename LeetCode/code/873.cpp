#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int res=0;
        map<int,bool> avail;
        map<int,int> num2index;
        vector<vector<int>> DP;
        int n=arr.size();
        DP.resize(n);
        for(int i=0;i<n;i++){
            DP[i].resize(n);
        }
        for(int i=0;i<arr.size();i++){
            avail[arr[i]]=true;
            num2index[arr[i]]=i;
        }
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]-arr[i]>=arr[i]||avail[arr[j]-arr[i]]==false){
                    DP[i][j]=0;
                }else{
                    int k=num2index[arr[j]-arr[i]];
                    DP[i][j]=max(3,DP[k][i]+1);
                    if(DP[i][j]>res){
                        res=DP[i][j];
                    }
                }
            }
        }
        return res;
    }
};