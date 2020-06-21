# Same Tree :star:
- 题目地址: [https://leetcode-cn.com/problems/same-tree](https://leetcode-cn.com/problems/same-tree)
- 执行时间: 4 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-21 14:40
## 题目内容
<p>给定两个二叉树，编写一个函数来检验它们是否相同。</p>

<p>如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>      1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

<strong>输出:</strong> true</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:  </strong>    1          1
          /           \
         2             2

        [1,2],     [1,null,2]

<strong>输出:</strong> false
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong>       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

<strong>输出:</strong> false
</pre>

## 解法
```cpp
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

```