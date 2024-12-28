#include <bits/stdc++.h>
using namespace std;

class Dequeu {
public:
    int size, cap, *arr;

    // Constructor to initialize deque with capacity 'c'
    Dequeu(int c) {
        cap = c;
        size = 0;
        arr = new int[c];
    }

    // Pushes 'X' to the front of the deque. Returns -1 if full, otherwise 0.
    int pushFront(int x) {
        if (isFull()) {
            return -1;
        } else {
            for (int i = size - 1; i >= 0; --i) {
                arr[i + 1] = arr[i]; // Shift all elements to the right
            }
            arr[0] = x; // Insert at the front
            size++;
            return 0; // Success
        }
    }

    // Pushes 'X' to the rear of the deque. Returns -1 if full, otherwise 0.
    int pushRear(int x) {
        if (isFull()) {
            return -1;
        } else {
            arr[size] = x; // Insert at the back
            size++;
            return 0; // Success
        }
    }

    // Pops an element from the front of the deque. Returns -1 if empty, otherwise the popped element.
    int popFront() {
        if (isEmpty()) {
            return -1;
        } else {
            int val = arr[0];
            for (int i = 0; i < size - 1; ++i) {
                arr[i] = arr[i + 1]; // Shift all elements to the left
            }
            size--;
            return val;
        }
    }

    // Pops an element from the rear of the deque. Returns -1 if empty, otherwise the popped element.
    int popRear() {
        if (isEmpty()) {
            return -1;
        } else {
            size--;
            return arr[size]; // Return last element and decrease size
        }
    }

    // Returns the front element of the deque. Returns -1 if empty.
    int getFront() {
        if (isEmpty()) {
            return -1;
        } else {
            return arr[0];
        }
    }

    // Returns the rear element of the deque. Returns -1 if empty.
    int getRear() {
        if (isEmpty()) {
            return -1;
        } else {
            return arr[size - 1];
        }
    }

    // Checks if the deque is full.
    bool isFull() {
        return size == cap;
    }

    // Checks if the deque is empty.
    bool isEmpty() {
        return size == 0;
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
