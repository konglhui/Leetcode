# Same Tree :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/same-tree](https://leetcode-cn.com/problems/same-tree)
- ִ��ʱ��: 4 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-21 14:40
## ��Ŀ����
<p>������������������дһ�����������������Ƿ���ͬ��</p>

<p>����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�</p>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����: </strong>      1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

<strong>���:</strong> true</pre>

<p><strong>ʾ�� 2:</strong></p>

<pre><strong>����:  </strong>    1          1
          /           \
         2             2

        [1,2],     [1,null,2]

<strong>���:</strong> false
</pre>

<p><strong>ʾ���0�23:</strong></p>

<pre><strong>����:</strong>       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

<strong>���:</strong> false
</pre>

## �ⷨ
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