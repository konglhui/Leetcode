# Remove Duplicates from Sorted List :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list)
- ִ��ʱ��: 12 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-20 20:56
## ��Ŀ����
<p>����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�</p>

<p><strong>ʾ���0�21:</strong></p>

<pre><strong>����:</strong> 1->1->2
<strong>���:</strong> 1->2
</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre><strong>����:</strong> 1->1->2->3->3
<strong>���:</strong> 1->2->3</pre>

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