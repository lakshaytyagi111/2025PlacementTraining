// Design Stack using Arrays
// ○ The data structure should contain functions like top, push, pop and peep.
// ○ peep() function allows the user inspect values at any position in a stack

#include <iostream>
using namespace std;

class stack {
    private:
        int* array;
        int capacity;
        int top;
    public:
        stack(int x){
            capacity = x;
            array = new int[capacity];
            top = -1;
        }
        int topEle(){
            if (top==-1){
                return -1;
            }
            else {
                return array[top];
            }
        }
        int pop(){
            if (isEmpty()){
                cout << 'Empty stack'<< endl;
                return -1;
            } else {
                int topElement = array[top];
                top--;
                cout << "Popped "<< topElement << "From the stack" << endl;
                return topElement;
            }
        }
        void push(int m){
            if (isFull()){
                cout << "Stack is already full!" << endl;
                return;
            } else {
                top++;
                array[top] = m;
                cout << m << " Pushed into stack." << endl;
            }
        }
        int peep(int n){
            if (top>=n){
                cout << "Element at index " << n << " is "<< array[n]<< endl; 
                return array[n];
            } else {
                cout << "Index out of range" << endl;
                return -1;
            }
        }
        bool isFull(){
            if (top+1 == capacity){
                return true;
            } else return false;
        }
        bool isEmpty(){
            if (top ==  -1){
                return true;
            } else return false;
        }
};
int main(){
    stack s1(5);
    cout << s1.isEmpty() << endl;
    cout << s1.isFull() << endl;


    int p2 = s1.topEle();

    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    int p3 = s1.peep(3);
    s1.push(5);
    s1.push(7);
    s1.push(8);
    int p4 = s1.pop();
    int p5 = s1.pop();
    int p6 = s1.pop();

    cout << s1.isEmpty() << endl;
    cout << s1.isFull() << endl;
    
}