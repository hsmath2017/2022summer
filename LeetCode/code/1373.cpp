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
private:
    map<TreeNode*,bool> isBSTroot;
    map<TreeNode*,int> key;
public:
    int findmin(TreeNode* TN){
        if(TN->left==nullptr){
            return TN->val;
        }
        return findmin(TN->left);
    }
    int findmax(TreeNode* TN){
        if(TN->right==nullptr){
            return TN->val;
        }
        return findmax(TN->right);
    }
    bool check(TreeNode* TN){
        if(!TN){
            return true;
        }
        isBSTroot[TN]=true;
        bool c1=check(TN->left);
        bool c2=check(TN->right);
        if(c1==false||c2==false){
            isBSTroot[TN]=false;
            return false;
        }
        if(TN->right){
            int d=findmin(TN->right);
            if(TN->val>=d){
                isBSTroot[TN]=false;
            }
        }
        if(TN->left){
            int x=findmax(TN->left);
            if(TN->val<=x){
                isBSTroot[TN]=false;
            }
        }
        return isBSTroot[TN];
    }
    int getKey(TreeNode* TN){
        if(!TN){
            return 0;
        }
        int c1=getKey(TN->left);
        int c2=getKey(TN->right);
        key[TN]=c1+c2+TN->val;
        return key[TN];
    }
    int maxSumBST(TreeNode* root) {
        int res=0;
        check(root);
        getKey(root);
        for(auto it:isBSTroot){
            if(it.second==true){
                if(key[it.first]>res){
                    res=key[it.first];
                }
            }
        }
        return res;
    }
};