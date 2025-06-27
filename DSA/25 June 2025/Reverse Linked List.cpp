// https://leetcode.com/problems/reverse-linked-list/

// by recursion
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next){
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head -> next -> next = head;
        head -> next = nullptr;

        return newHead;
    }
};

// by iteration
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (current != nullptr){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};