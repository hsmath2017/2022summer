#include<bits/stdc++.h>
using namespace std;
class TNode{
public:
    int left;
    int right;
    TNode(){
        left=-1;
        right=-1;
    }
};
class Solution {
private:
    vector<TNode> Binary_Tree;
    map<int,int> score;
public:
    int dfs(int id){
        if(id==-1){
            return 0;
        }
        score[id]=dfs(Binary_Tree[id].left)+dfs(Binary_Tree[id].right)+1;
        return score[id];
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        Binary_Tree.resize(n);
        //step1: construct a binary tree
        for(int i=1;i<parents.size();i++){
            if(Binary_Tree[parents[i]].left==-1){
                Binary_Tree[parents[i]].left=i;
            }else{
                Binary_Tree[parents[i]].right=i;
            }
        }
        //step2: DFS, calculate the score of each sub-trees.
        dfs(0);
        score[-1]=1;
        //step3: Solve the problem by traverse
        long nowmax=0;
        int now_max_val_num=1;
        for(int i=0;i<n;i++){
            long now;
            if(i==0){
                now=(long)score[Binary_Tree[i].left]*(long)score[Binary_Tree[i].right];
            }else{
                now=(long)(score[0]-score[i])*(long)score[Binary_Tree[i].left]*(long)score[Binary_Tree[i].right];
            }
            if(now==nowmax){
                now_max_val_num++;
            }else if(now>nowmax){
                nowmax=now;
                now_max_val_num=1;
            }
        }
        return now_max_val_num;
    }
};