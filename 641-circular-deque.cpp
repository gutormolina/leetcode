#include <iostream>
using namespace std;

class MyCircularDeque
{
private:
    int front, rear, size;
    int *deque;

public:
    MyCircularDeque(int k) : rear(-1), front(-1)
    {
        deque = new int[k];
        size = k;
    }

    bool insertFront(int value)
    {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        }

        else {
            front = (front - 1 + size) % size;
        }

        deque[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        
        else {
            rear = (rear + 1) % size;
        }

        deque[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = rear = -1;
        }

        else {
            front = (front + 1) % size;
        }

        return true;
    }

    bool deleteLast()
    {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = rear = -1;
        }

        else {
            rear = (rear - 1) % size;
        }
        
        return true;
    }

    int getFront()
    {
        if (isEmpty()) {
            return -1;
        }

        return deque[front];
    }

    int getRear()
    {
        if (isEmpty()) {
            return -1;
        }

        return deque[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }
};

int main() {
    MyCircularDeque deque(3);
    cout << boolalpha << deque.insertLast(1) << endl;
    cout << boolalpha << deque.insertLast(2) << endl;
    cout << boolalpha << deque.insertFront(3) << endl;
    cout << boolalpha << deque.insertFront(4) << endl;
    cout << deque.getRear() << endl;
    cout << boolalpha << deque.isFull() << endl;
    cout << boolalpha << deque.deleteLast() << endl;
    cout << boolalpha << deque.insertFront(4) << endl;
    cout << deque.getFront() << endl;
}
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */