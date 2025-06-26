// 1. Design a Singly Linked List and write functions to
// ○ Insert at beginning
// ○ Insert at end
// ○ Insert at any index
// ○ Delete at beginning
// ○ Delete at end
// ○ Delete at index

// ○ Delete first occurrence of node with given value
// ○ Write at least 2 test cases for each operation

#include <iostream>
#include <stdio.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value): data(value), next(nullptr){}
};

class LinkedList {
    private:
        Node* head;
        int size;
    public:
        LinkedList(): head(nullptr), size(0) {}
        void insertAtBeginning(int n) {
            Node* newNode = new Node(n);
            newNode -> next = head;
            head = newNode;
            size++;
        }
        void insertAtEnd(int n) {
            Node* newNode = new Node(n);
            
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
            size++;
        }
        void insertAtPlace(int value, int n) {
            
            if (n < 0 || n > size){
                cout << "Index out of bounds" << endl;
                return;
            } 

            if (n == 0){
                insertAtBeginning(value);
            } 

            Node* newNode = new Node(value);
            Node* current = head;

            for (int i = 0; i < n-1; i++){
                current = current -> next;
            }

            newNode -> next = current->next;
            current->next = newNode;
            size++;
        }
        bool deleteAtBeginning() {
            if (size == 0){
                cout << "Empty List" << endl;
                return false;
            }

            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        bool deleteAtEnd() {
            if (size == 0) {
                cout << "Empty List" << endl;
                return false;
            }
            
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                size--;
                return true;
            }
            
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            
            delete current->next;
            current->next = nullptr;
            size--;
            return true;
        }
        bool deleteAtIndex(int index){
            if (index < 0 || index >= size) {
                cout << "index out of bounds" << endl;
                return false;
            }
            
            if (index == 0) {
                return deleteAtBeginning();
            }
            
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return true;
        }
        bool deleteFirstOccurrence(int value) {
            if (head == nullptr) {
                cout << "Empty List" << endl;
                return false;
            }
            
            if (head->data == value) {
                return deleteAtBeginning();
            }
            
            Node* current = head;
            while (current->next != nullptr && current->next->data != value) {
                current = current->next;
            }
            
            if (current->next == nullptr) {
                cout << "not found" << endl;
                return false;
            }
            
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return true;
        }
        void display() {
            if (head == nullptr) {
                cout << "list is empty" << endl;
                return;
            }
            
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList list1;
    list1.insertAtBeginning(10);
    list1.insertAtBeginning(20);

    list1.display();

    LinkedList list2;
    list2.insertAtBeginning(5);
    list2.display();

    LinkedList list3;
    list3.insertAtEnd(1);
    list3.insertAtEnd(2);
    list3.insertAtEnd(3);
    list3.display();

    LinkedList list4;
    list4.insertAtEnd(1);
    list4.insertAtEnd(3);
    list4.insertAtEnd(6);
    list4.insertAtPlace(1, 2); 
    list4.display();

    LinkedList list5;
    list5.insertAtEnd(10);
    list5.insertAtPlace(0, 5); 
    list5.display();
    return 0;

    LinkedList list6;
    list6.insertAtEnd(1);
    list6.insertAtEnd(2);
    list6.insertAtEnd(3);
    list6.deleteAtBeginning();
    list6.display();

    LinkedList list7;
    list7.insertAtEnd(42);
    list7.deleteAtBeginning();
    list7.display();


    LinkedList list8;
    list8.insertAtEnd(1);
    list8.insertAtEnd(2);
    list8.insertAtEnd(3);
    list8.insertAtEnd(2);
    list8.deleteFirstOccurrence(2);
    list8.display();
    return 0;
}