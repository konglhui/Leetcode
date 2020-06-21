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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode result(0);
        ListNode* p = &result;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val > l2->val )
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1 = l1->next;
            }
            
            p = p->next;
        }
        
        p->next = l1 != nullptr ?l1:l2;
        return result.next;
    }
};
