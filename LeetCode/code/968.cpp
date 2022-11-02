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
    int ans=0;
    int state(TreeNode* TN){
        if(TN==nullptr){
            return 2;
        }
        int left=state(TN->left);
        int right=state(TN->right);
        if(left==0||right==0){
            ans++;
            return 1;//need a camera！
        }
        if(left==1||right==1){
            return 2;//monitored!
        }
        if(left==2&&right==2){
            return 0;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(state(root)==0){
            ans++;
        }
        return ans;
    }
};