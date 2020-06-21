# Reverse Linked List :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/reverse-linked-list](https://leetcode-cn.com/problems/reverse-linked-list)
- ִ��ʱ��: 12 ms 
- �ڴ�����: 8.3 MB
- ͨ������: 2020-06-09 23:54
## ��Ŀ����
<p>��תһ��������</p>

<p><strong>ʾ��:</strong></p>

<pre><strong>����:</strong> 1->2->3->4->5->NULL
<strong>���:</strong> 5->4->3->2->1->NULL</pre>

<p><strong>����:</strong><br>
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿</p>

## �ⷨ
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