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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> queue;
        int level=0;
        queue.push_back(root);
        while(!queue.empty()){
            if(level%2){
                vector<int> data;
                for(auto it:queue){
                    data.push_back(it->val);
                }
                reverse(data.begin(),data.end());
                for(int i=0;i<queue.size();i++){
                    queue[i]->val=data[i];
                }
            }
            vector<TreeNode*> tmp;
            for(auto it:queue){
                if(it->left){
                    tmp.push_back(it->left);
                }
                if(it->right){
                    tmp.push_back(it->right);
                }
            }
            queue=tmp;
            level++;
        }
        return root;
    }
};