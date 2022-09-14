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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        queue<TreeNode*> BFS_Queue;
        BFS_Queue.push(root);
        int d=1;
        while(BFS_Queue.empty()==false){
            if(d==depth-1){
                while(!BFS_Queue.empty()){
                    auto node=BFS_Queue.front();
                    auto LeftNode=node->left;
                    auto RightNode=node->right;
                    node->left=new TreeNode(val);
                    node->left->left=LeftNode;
                    node->right=new TreeNode(val);
                    node->right->right=RightNode;
                    BFS_Queue.pop();
                }
                break;
            }else{
                queue<TreeNode*> tmp;
                while(!BFS_Queue.empty()){
                    auto node=BFS_Queue.front();
                    BFS_Queue.pop();
                    if(node->left){
                        tmp.push(node->left);
                    }
                    if(node->right){
                        tmp.push(node->right);
                    }
                }
                BFS_Queue=tmp;
            }
            d++;
        }
        return root;
    }
};