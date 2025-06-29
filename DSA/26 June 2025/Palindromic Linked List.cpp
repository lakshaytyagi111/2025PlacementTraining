// https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    ListNode* reversed(ListNode* head){
        if (!head || !head -> next) return head;
        ListNode* current = head;
        ListNode* newHead = reversed(current->next);

        current-> next -> next = head;
        current->next = nullptr;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revHead = reversed(slow);
        while(head && revHead){
            if ((head->val != revHead->val)){
                return false;
            }
            head = head->next;
            revHead = revHead->next;
        }
        return true;
    }
};