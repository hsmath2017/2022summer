## Problem#1.计算布尔二叉树的值
签到题来了道二叉树，顿时觉得这场双周赛来者不善...
不过好在题目本身还是很简单的...
### 问题描述
给你一棵 完整二叉树 的根，这棵树有以下特征：

    叶子节点 要么值为 0 要么值为 1 ，其中 0 表示 False ，1 表示 True 。
    非叶子节点 要么值为 2 要么值为 3 ，其中 2 表示逻辑或 OR ，3 表示逻辑与 AND 。

计算 一个节点的值方式如下：

    如果节点是个叶子节点，那么节点的值为它本身，即 True 或者 False 。
    否则，计算 两个孩子的节点值，然后将该节点的运算符对两个孩子值进行 运算 。

返回根节点 root 的布尔运算值。

**完整二叉树**是每个节点有 0 个或者 2 个孩子的二叉树。

**叶子节点**是没有孩子的节点。
### 分析
一眼DFS。根节点的值与它的俩子节点相关，子节点的值可以递归求解。
### 代码
```cpp
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
    bool evaluateTree(TreeNode* root) {
        if(root->left==nullptr){
            return root->val;
        }
        if(root->val==2){
            return (evaluateTree(root->left)|evaluateTree(root->right));
        }else{
            return (evaluateTree(root->left)&evaluateTree(root->right));
        }
    }
};
```