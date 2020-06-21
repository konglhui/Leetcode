# Swap Nodes in Pairs :star::star:
- 题目地址: [https://leetcode-cn.com/problems/swap-nodes-in-pairs](https://leetcode-cn.com/problems/swap-nodes-in-pairs)
- 执行时间: 4 ms 
- 内存消耗: 6.4 MB
- 通过日期: 2020-06-12 22:15
## 题目内容
<p>给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。</p>

<p><strong>你不能只是单纯的改变节点内部的值</strong>，而是需要实际的进行节点交换。</p>



<p><strong>示例:</strong></p>

<pre>给定 <code>1->2->3->4</code>, 你应该返回 <code>2->1->4->3</code>.
</pre>

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
	bool swapListNode(ListNode* node)
	{
		if (node->next == nullptr || node->next->next == nullptr)
			return false;

		auto temp = node->next->next;
		node->next->next = temp->next;
		temp->next = node->next;
		node->next = temp;
		return true;
	}

	public:
	ListNode* swapPairs(ListNode* head) {
		ListNode res(0);
		res.next = head;
		auto* node = &res;
		while (swapListNode(node))
		{
			node = node->next->next;
		}
		return res.next;
	}
};

```