// https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        Node* current = head;
        if (x==1){
            head = current->next;
            return head;
        }
        for (int i = 2; i < x && current != nullptr; i++){
            current = current -> next;
        }
        
        Node* temp = current;
        if (current -> next -> next){
            current->next = current->next->next;
        } else {
            current->next = nullptr;
        }
        
        return head;
    }
};