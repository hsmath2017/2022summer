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
    map<int,TreeNode*> father;
    map<int,TreeNode*> val2TN;
    void dfs(TreeNode* TN){
        if(!TN){
            return;
        }
        if(TN->left){
            father[TN->left->val]=TN;
        }
        if(TN->right){
            father[TN->right->val]=TN;
        }
        val2TN[TN->val]=TN;
        dfs(TN->left);
        dfs(TN->right);
        return;
    }
    int bfs(int start){
        int ans=0;
        vector<TreeNode*> vec;
        vec.push_back(val2TN[start]);
        map<TreeNode*,bool> avail;
        while(vec.empty()==false){
            vector<TreeNode*> tmp;
            for(auto nd:vec){
                avail[nd]=true;
                if(nd->left&&!avail[nd->left]){
                    tmp.push_back(nd->left);
                }
                if(nd->right&&!avail[nd->right]){
                    tmp.push_back(nd->right);
                }
                if(father[nd->val]&&!avail[father[nd->val]]){
                    tmp.push_back(father[nd->val]);
                }
            }
            swap(vec,tmp);
            ans++;
        }
        ans--;
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        father[root->val]=nullptr;
        dfs(root);
        int ans=bfs(start);
        return ans;
    }
};