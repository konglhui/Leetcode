# Merge Two Sorted Lists :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/merge-two-sorted-lists](https://leetcode-cn.com/problems/merge-two-sorted-lists)
- ִ��ʱ��: 8 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-11 00:49
## ��Ŀ����
<p>��������������ϲ�Ϊһ���µ� <strong>����</strong> �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ��0�2</p>



<p><strong>ʾ����</strong></p>

<pre><strong>���룺</strong>1->2->4, 1->3->4
<strong>�����</strong>1->1->2->3->4->4
</pre>

## �ⷨ
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