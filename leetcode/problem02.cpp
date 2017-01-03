#include <iostream>


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = NULL;
        ListNode** next = &root;
        int over = 0;

        while (l1 != NULL || l2 != NULL) {
            int left = 0;
            int right = 0;
            if (l1 != NULL) {
                left = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                right = l2->val;
                l2 = l2->next;
            }
            int sum = left + right + over;
            *next = new ListNode(sum % 10);
            over = sum / 10;
            next = &(*next)->next;
        }

        if (over > 0) {
            *next = new ListNode(over);
        }

        return root;
    }
};