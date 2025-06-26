// https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        int size = 0;
        while (current->next != nullptr){
            size++;
            current = current->next;
        }

        int mid = ceil((size+1)/2);
        current = head;
        while (mid--){
            current = current->next;
        }

        return current;
    }
};