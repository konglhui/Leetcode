# Remove Duplicates from Sorted List :star:
- 题目地址: [https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list)
- 执行时间: 12 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-20 20:56
## 题目内容
<p>给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 1->1->2
<strong>输出:</strong> 1->2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 1->1->2->3->3
<strong>输出:</strong> 1->2->3</pre>

## 解法
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* rear = head;
        ListNode*first = head->next;
        while(rear && first)
        {
            if(rear->val == first->val)
            {
                rear->next = first->next;
                first = rear->next;
            }
            else
            {
                rear = rear->next;
                first = rear->next;
            }

        }
        return head;
    }
};

```