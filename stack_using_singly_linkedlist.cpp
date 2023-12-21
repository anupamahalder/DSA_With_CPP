class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
class Stack
{
    //Write your code here
private:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
public:
    Stack()
    {
        //Write your code here
    }

    int getSize()
    {
        //Write your code here
        return sz;
    }

    bool isEmpty()
    {
        //Write your code here
        return sz==0;
    }

    void push(int data)
    {
        //Write your code here
        Node *newNode = new Node(data);
        sz++;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        //Write your code here
        if(head == NULL) return;
        sz--;
        Node *deleteNode = tail;
        if(head->next == NULL){
            tail = NULL;
            head = NULL;
            delete deleteNode;
            return;
        }
        Node *tmp = head;
        while(tmp->next != NULL){
            if(tmp->next == tail){
                tmp->next = NULL;
                delete deleteNode;
                tail = tmp;
                return;
            }
            tmp = tmp->next;
        }
    }

    int getTop()
    {
        //Write your code here
        if(sz==0) return -1;
        return tail->data; 
    }
};
