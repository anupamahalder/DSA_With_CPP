#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor 
    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize queue 
    LinkedListQueue(){
        this->front = nullptr;
        this->rear = nullptr;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    // insert element to queue 
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    // delete element from queue 
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }
    int getFront() {
        return isEmpty() ? -1 : front->data;
    }

    int getRear() {
        return isEmpty() ? -1 : rear->data;
    }
    void printQueue() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedListQueue myQueue;
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.enqueue(8);
    myQueue.enqueue(10);

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
