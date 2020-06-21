# Swap Nodes in Pairs :star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/swap-nodes-in-pairs](https://leetcode-cn.com/problems/swap-nodes-in-pairs)
- ִ��ʱ��: 4 ms 
- �ڴ�����: 6.4 MB
- ͨ������: 2020-06-12 22:15
## ��Ŀ����
<p>����һ���������������������ڵĽڵ㣬�����ؽ����������</p>

<p><strong>�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ</strong>��������Ҫʵ�ʵĽ��нڵ㽻����</p>



<p><strong>ʾ��:</strong></p>

<pre>���� <code>1->2->3->4</code>, ��Ӧ�÷��� <code>2->1->4->3</code>.
</pre>

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