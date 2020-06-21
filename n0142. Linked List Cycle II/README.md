# Linked List Cycle II :star::star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/linked-list-cycle-ii](https://leetcode-cn.com/problems/linked-list-cycle-ii)
- ִ��ʱ��: 8 ms 
- �ڴ�����: 7.6 MB
- ͨ������: 2020-06-12 22:56
## ��Ŀ����
<p>����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣�0�2��������޻����򷵻؁0�2<code>null</code>��</p>

<p>Ϊ�˱�ʾ���������еĻ�������ʹ������ <code>pos</code> ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� <code>pos</code> �� <code>-1</code>�����ڸ�������û�л���</p>

<p><strong>˵����</strong>�������޸ĸ���������</p>



<p><strong>ʾ�� 1��</strong></p>

<pre><strong>���룺</strong>head = [3,2,0,-4], pos = 1
<strong>�����</strong>tail connects to node index 1
<strong>���ͣ�</strong>��������һ��������β�����ӵ��ڶ����ڵ㡣
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png" style="height: 97px; width: 300px;"></p>

<p><strong>ʾ���0�22��</strong></p>

<pre><strong>���룺</strong>head = [1,2], pos = 0
<strong>�����</strong>tail connects to node index 0
<strong>���ͣ�</strong>��������һ��������β�����ӵ���һ���ڵ㡣
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 74px; width: 141px;"></p>

<p><strong>ʾ�� 3��</strong></p>

<pre><strong>���룺</strong>head = [1], pos = -1
<strong>�����</strong>no cycle
<strong>���ͣ�</strong>������û�л���
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 45px; width: 45px;"></p>



<p><strong>���ף�</strong><br>
���Ƿ���Բ��ö���ռ������⣿</p>

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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        auto one = head, two = head;
		while (two->next && two->next->next)
		{
			one = one->next;
			two = two->next->next;
			if (one == two)
			{
				while (true)
				{
					if (head == one)
						return head;
					head = head->next;
					one = one->next;
				}
			}
		}
		return nullptr;
    }
};

```