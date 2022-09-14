#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> dist_arr_node_1;
    vector<int> dist_arr_node_2;
    const int INFTY=1e6;
public:
    void travel(vector<int>& arr,int start,const vector<int>& edges){
        int i=start;
        int dist=0;
        while(i!=-1){
            if(arr[i]!=-1){
                break;
            }
            arr[i]=dist;
            dist++;
            i=edges[i];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        dist_arr_node_1.resize(n);
        dist_arr_node_2.resize(n);
        for(int i=0;i<n;i++){
            dist_arr_node_1[i]=-1;
            dist_arr_node_2[i]=-1;
        }
        travel(dist_arr_node_1,node1,edges);
        travel(dist_arr_node_2,node2,edges);
        int nowmin=INFTY;
        int res=0;
        for(int i=0;i<n;i++){
            if(dist_arr_node_1[i]==-1||dist_arr_node_2[i]==-1){
                continue;
            }
            int x=max(dist_arr_node_1[i],dist_arr_node_2[i]);
            if(x<nowmin){
                nowmin=x;
                res=i;
            }
        }
        if(nowmin==INFTY){
            return -1;
        }
        return res;
    }
};