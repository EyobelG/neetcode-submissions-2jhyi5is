/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // step 1: check if there are at least k nodes left in the list
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == nullptr) {
                return head;
            }
            check = check->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
       
        }
        
        if (curr != nullptr) {
            head->next = reverseKGroup(curr, k);
        }

        return prev;

    }

};

/*
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
*/