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
