// Queue implementation using array
#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 10;

class ArrayQueue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    // initialize front and rear 
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Queue is full!" << std::endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        // insert value to the queue 
        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return arr[rear];
    }
    void printQueue(){
        if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        int i = front;
        do {
            std::cout << arr[i] << " ";
            // Circular adjustment
            i = (i + 1) % MAX_SIZE; 
        } while (i != (rear + 1) % MAX_SIZE);

        cout<<endl;
    }
};
int main(){
    ArrayQueue myQueue;
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.enqueue(8);

    // print queue element 
    myQueue.printQueue();
    //delete element from queue 
    myQueue.dequeue();
    myQueue.printQueue();
    // get the front element of queue 
    cout<<myQueue.getFront()<<endl;
    // get the rear element of queue 
    cout<<myQueue.getRear()<<endl;
    return 0;
}
