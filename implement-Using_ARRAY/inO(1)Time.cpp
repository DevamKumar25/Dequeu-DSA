#include <bits/stdc++.h>
using namespace std;

class Dequeu {
public:
    int size, cap, *arr, front, rear;

    Dequeu(int c) {
        cap = c;
        size = 0;
        arr = new int[c];
        front = 0;
        rear = 0;
    }

    int pushFront(int x) {
        if (isFull()) {
            return -1; // Deque is full
        } else {
            front = (front - 1 + cap) % cap;
            arr[front] = x; 
            size++;
            return 0; 
        }
    }

    int pushRear(int x) {
        if (isFull()) {
            return -1; 
        } else {
            arr[rear] = x; 
            rear = (rear + 1) % cap;
            size++;
            return 0; 
        }
    }

    int popFront() {
        if (isEmpty()) {
            return -1; 
        } else {
            int val = arr[front];
            front = (front + 1) % cap; 
            size--;
            return val; 
        }
    }

   
    int popRear() {
        if (isEmpty()) {
            return -1;
        } else {
            rear = (rear - 1 + cap) % cap; 
            int val = arr[rear];
            size--;
            return val; 
        }
    }

    // Returns the front element of the deque. Returns -1 if empty.
    int getFront() {
        if (isEmpty()) {
            return -1; // Deque is empty
        } else {
            return arr[front];
        }
    }

    
    int getRear() {
        if (isEmpty()) {
            return -1; // Deque is empty
        } else {
           
            return arr[(rear - 1 + cap) % cap]; 
        }
    }

    // Checks if the deque is full.
    bool isFull() {
        return size == cap; // Full if size equals capacity
    }

    // Checks if the deque is empty.
    bool isEmpty() {
        return size == 0; // Empty if size is 0
    }
};

int main() {
    // Creating deque with capacity 5
    Dequeu dq(5);

    // Test cases based on your provided code
    cout << "pushFront(21): " << (dq.pushFront(21) == 0 ? "True" : "False") << endl;
    cout << "getFront(): " << dq.getFront() << endl;
    cout << "pushFront(11): " << (dq.pushFront(11) == 0 ? "True" : "False") << endl;
    cout << "getRear(): " << dq.getRear() << endl;
    cout << "pushRear(34): " << (dq.pushRear(34) == 0 ? "True" : "False") << endl;
    cout << "getFront(): " << dq.getFront() << endl;
    cout << "pushFront(25): " << (dq.pushFront(25) == 0 ? "True" : "False") << endl;
    cout << "getRear(): " << dq.getRear() << endl;
    cout << "pushFront(27): " << (dq.pushFront(27) == 0 ? "True" : "False") << endl;
    cout << "getFront(): " << dq.getFront() << endl;

    cout << "popFront(): " << dq.popFront() << endl;
    cout << "pushRear(34): " << (dq.pushRear(34) == 0 ? "True" : "False") << endl;
    cout << "pushFront(61): " << (dq.pushFront(61) == 0 ? "True" : "False") << endl;
    cout << "getRear(): " << dq.getRear() << endl;
    cout << "pushRear(34): " << (dq.pushRear(34) == 0 ? "True" : "False") << endl;
    cout << "popRear(): " << dq.popRear() << endl;

    return 0;
}
