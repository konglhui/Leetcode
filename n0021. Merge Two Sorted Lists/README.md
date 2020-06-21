# Merge Two Sorted Lists :star:
- 题目地址: [https://leetcode-cn.com/problems/merge-two-sorted-lists](https://leetcode-cn.com/problems/merge-two-sorted-lists)
- 执行时间: 8 ms 
- 内存消耗: N/A
- 通过日期: 2019-04-11 00:49
## 题目内容
<p>将两个升序链表合并为一个新的 <strong>升序</strong> 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 </p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>1->2->4, 1->3->4
<strong>输出：</strong>1->1->2->3->4->4
</pre>

## 解法
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode result(0);
        ListNode* p = &result;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val > l2->val )
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1 = l1->next;
            }
            
            p = p->next;
        }
        
        p->next = l1 != nullptr ?l1:l2;
        return result.next;
    }
};

```