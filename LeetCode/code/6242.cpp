#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void inorder(TreeNode* TN,vector<int>& sortedseq){
        if(!TN){
            return;
        }
        inorder(TN->left,sortedseq);
        sortedseq.push_back(TN->val);
        inorder(TN->right,sortedseq);
        return;
    }
    int BinaryFindMax(const vector<int>& sequence,int Left,int Right,int target){
        if(sequence[Left]>target){
            return -1;
        }
        if(Left==Right){
            return Left;
        }
        int mid=(Left+Right)/2;
        if(sequence[mid]<=target){
            return BinaryFindMax(sequence,mid,Right,target);
        }else{
            return BinaryFindMax(sequence,Left,mid-1,target);
        }
    }
    int BinaryFindMin(const vector<int>& sequence,int Left,int Right,int target){
        if(sequence[Right]<target){
            return -1;
        }
        if(Left==Right){
            return Left;
        }
        int mid=(Left+Right)/2;
        if(sequence[mid]>=target){
            return BinaryFindMin(sequence,mid,Right,target);
        }else{
            return BinaryFindMin(sequence,Left,mid-1,target);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sortedseq;
        inorder(root,sortedseq);
        int n=sortedseq.size();
        vector<vector<int>> ans;
        for(auto c:queries){
            int x=BinaryFindMax(sortedseq,0,n-1,c);
            int y=BinaryFindMin(sortedseq,0,n-1,c);
            ans.push_back(vector<int>{x,y});
        }
        return ans;
    }
};