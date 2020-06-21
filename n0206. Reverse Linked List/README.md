# Reverse Linked List :star:
- 题目地址: [https://leetcode-cn.com/problems/reverse-linked-list](https://leetcode-cn.com/problems/reverse-linked-list)
- 执行时间: 12 ms 
- 内存消耗: 8.3 MB
- 通过日期: 2020-06-09 23:54
## 题目内容
<p>反转一个单链表。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1->2->3->4->5->NULL
<strong>输出:</strong> 5->4->3->2->1->NULL</pre>

<p><strong>进阶:</strong><br>
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？</p>

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
    ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
        ListNode* pre = NULL;
		while (cur != NULL)
		{
            auto t = cur->next;
            cur->next = pre;
			pre = cur;
            cur = t;
		}
		return pre; 
    }
};

```