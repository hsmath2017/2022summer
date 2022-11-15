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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<TreeNode*,int> Height;
        function<int(TreeNode*)> getHeight=[&](TreeNode* TN){
            if(TN==nullptr){
                return 0;
            }
            Height[TN]=1+max(getHeight(TN->left),getHeight(TN->right));
            return Height[TN];
        };
        getHeight(root);
        vector<int> ans(Height.size()+1);
        function<void(TreeNode*,int,int)> dfs=[&](TreeNode* TN,int depth,int resH){
            if(TN==nullptr){
                return;
            }
            ++depth;
            ans[TN->val]=resH;
            dfs(TN->left,depth,max(resH,depth+Height[TN->right]));
            dfs(TN->right,depth,max(resH,depth+Height[TN->left]));
        };
        dfs(root,-1,0);
        vector<int> res;
        for(auto q:queries){
            res.push_back(ans[q]);
        }
        return res;
    }
};