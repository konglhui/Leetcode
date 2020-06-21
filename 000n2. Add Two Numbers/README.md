# Add Two Numbers :star::star:
- 题目地址: [https://leetcode-cn.com/problems/add-two-numbers](https://leetcode-cn.com/problems/add-two-numbers)
- 执行时间: 40 ms 
- 内存消耗: N/A
- 通过日期: 2019-03-16 23:58
## 题目内容
<p>给出两个 <strong>非空</strong> 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 <strong>逆序</strong> 的方式存储的，并且它们的每个节点只能存储 <strong>一位</strong> 数字。</p>

<p>如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。</p>

<p>您可以假设除了数字 0 之外，这两个数都不会以 0 开头。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>(2 -> 4 -> 3) + (5 -> 6 -> 4)
<strong>输出：</strong>7 -> 0 -> 8
<strong>原因：</strong>342 + 465 = 807
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