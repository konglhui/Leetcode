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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* rear = head;
        ListNode*first = head->next;
        while(rear && first)
        {
            if(rear->val == first->val)
            {
                rear->next = first->next;
                first = rear->next;
            }
            else
            {
                rear = rear->next;
                first = rear->next;
            }

        }
        return head;
    }
};
