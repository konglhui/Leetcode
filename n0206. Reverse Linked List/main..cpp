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
    ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
        ListNode* pre = NULL;
		while (cur != NULL)
		{
            auto t = cur->next;
            cur->next = pre;
			pre = cur;
            cur = t;
		}
		return pre; 
    }
};
