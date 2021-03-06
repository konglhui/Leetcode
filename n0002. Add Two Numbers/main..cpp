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
