# Linked List Cycle :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/linked-list-cycle](https://leetcode-cn.com/problems/linked-list-cycle)
- ִ��ʱ��: 8 ms 
- �ڴ�����: 7.6 MB
- ͨ������: 2020-06-12 22:45
## ��Ŀ����
<p>����һ�������ж��������Ƿ��л���</p>

<p>Ϊ�˱�ʾ���������еĻ�������ʹ������ <code>pos</code> ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� <code>pos</code> �� <code>-1</code>�����ڸ�������û�л���</p>



<p><strong>ʾ�� 1��</strong></p>

<pre><strong>���룺</strong>head = [3,2,0,-4], pos = 1
<strong>�����</strong>true
<strong>���ͣ�</strong>��������һ��������β�����ӵ��ڶ����ڵ㡣
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png" style="height: 97px; width: 300px;"></p>

<p><strong>ʾ���0�22��</strong></p>

<pre><strong>���룺</strong>head = [1,2], pos = 0
<strong>�����</strong>true
<strong>���ͣ�</strong>��������һ��������β�����ӵ���һ���ڵ㡣
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 74px; width: 141px;"></p>

<p><strong>ʾ�� 3��</strong></p>

<pre><strong>���룺</strong>head = [1], pos = -1
<strong>�����</strong>false
<strong>���ͣ�</strong>������û�л���
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 45px; width: 45px;"></p>



<p><strong>���ף�</strong></p>

<p>������ <em>O(1)</em>�������������ڴ�����������</p>

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
	bool hasCycle(ListNode* head) {
        if(!head)
        return false;
		auto one = head, two = head;
		while (two->next && two->next->next)
		{
			one = one->next;
			two = two->next->next;
			if (one == two)
				return true;
		}
		return false;
	}
};

```