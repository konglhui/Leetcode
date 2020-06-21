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
