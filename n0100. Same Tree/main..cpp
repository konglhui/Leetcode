// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == nullptr && q == nullptr)
            return true;
        else if(p == nullptr)
            return false;
        else if(q == nullptr)
            return false;
        
        if((p->val == q->val) &&isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
            return true;
        else
            return false;
    }
};