# Add Two Numbers :star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/add-two-numbers](https://leetcode-cn.com/problems/add-two-numbers)
- ִ��ʱ��: 40 ms 
- �ڴ�����: N/A
- ͨ������: 2019-03-16 23:58
## ��Ŀ����
<p>���������0�2<strong>�ǿ�</strong> ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��Ձ0�2<strong>����</strong>�0�2�ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢�0�2<strong>һλ</strong>�0�2���֡�</p>

<p>��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�</p>

<p>�����Լ���������� 0 ֮�⣬���������������� 0�0�2��ͷ��</p>

<p><strong>ʾ����</strong></p>

<pre><strong>���룺</strong>(2 -> 4 -> 3) + (5 -> 6 -> 4)
<strong>�����</strong>7 -> 0 -> 8
<strong>ԭ��</strong>342 + 465 = 807
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode result(0), *p = &result;
		int num = 0;
		while (l1||l2||num)
		{
			num += (l1 ? l1->val : 0) + (l2 ? l2->val : 0) ;
			p->next = new ListNode(num % 10);
			num /= 10;
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
			if (!l1)
			{
				if (num == 0 && l2)
				{
					p->next = l2;
					break;
				}
			}
			if (!l2)
			{
				if (num == 0 && l1)
				{
					p->next = l1;
					break;
				}
			}
		}
		return result.next;
    }
};

```