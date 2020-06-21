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
