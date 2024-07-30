#include <iostream>
using namespace std;

class MyCircularDeque
{
private:
    int front, rear;
    int size;
    int *deque;

public:
    MyCircularDeque(int k) : rear(-1), front(rear)
    {
        deque = new int[k];
        size = k;
    }

    bool insertFront(int value)
    {
        if (isFull() == true)
        {
            return false;
        }

        else if (isEmpty() == true)
        {
            front++;
        }

        rear = (rear + 1) % size;
        deque[rear] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull() == true) {
            return false;
        } 
        
        else if (isEmpty() == true) {
            insertFront(value);
            return true;
        }

        front = (front - 1) % size;
        deque[front] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty() == true) {
            return false;
        }

        if (front == rear) {
            front = -1;
            rear = front;
            return true;
        }

        front = (front + 1) % size;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty() == true) {
            return false;
        }

        if (rear == front) {
            rear = -1;
            front = rear;
            return true;
        }

        rear = (rear - 1) % size;
        return true;
    }

    int getFront()
    {
        if (isEmpty() == true) {
            return -1;
        }

        return deque[front];
    }

    int getRear()
    {
        if (isEmpty() == true) {
            return -1;
        }

        return deque[rear];
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1) {
            return true;
        }

        return false;
    }

    bool isFull()
    {
        if (isEmpty() == true) {
            return false;
        }

        if (rear == (size - 1) && front == 0) {
            return true;
        }

        if ((rear - front) == -1) {
            return true;
        }

        return false;
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