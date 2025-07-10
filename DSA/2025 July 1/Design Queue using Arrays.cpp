
#include <iostream>
using namespace std;

class queue {
    private:
        int* array;
        int capacity;
        int front;
    public:
        queue(int x){
            capacity = x;
            array = new int[capacity];
            front = -1;
        }
        int frontEle(){
           
        }
        int pop(){
            
        }
        void push(int m){
            
        }
        int peep(int n){
            
        }
        bool isFull(){
            if (front+1 == capacity){
                return true;
            } else return false;
        }
        bool isEmpty(){
            if (front ==  -1){
                return true;
            } else return false;
        }
};
int main(){
    queue q1(5);
    cout << q1.isEmpty() << endl;
    cout << q1.isFull() << endl;


    int p2 = q1.frontEle();

    q1.push(4);
    q1.push(3);
    q1.push(2);
    q1.push(1);

    int p3 = q1.peep(3);
    q1.push(5);
    q1.push(7);
    q1.push(8);
    int p4 = q1.pop();
    int p5 = q1.pop();
    int p6 = q1.pop();

    cout << q1.isEmpty() << endl;
    cout << q1.isFull() << endl;
    
}