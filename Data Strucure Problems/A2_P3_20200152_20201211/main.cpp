#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node*next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class Queue
{
public:
    Node * front;
    int count = 0;
    Node * rear;
    Queue ()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
            return false;
    }
    void enQuere(int item)
    {
        count ++;
        Node * newNode = new Node();
        newNode -> data = item;
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear -> next = newNode;
            rear = newNode;
        }
    }
    int deQueue()
    {
        count--;
        int delvalue = -1;
        if (isEmpty())
        {
            cout << "Queue is Empty"<<endl;
        }
        else if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node * delptr = front;
            front = front->next ;
            delvalue = delptr->data;
            delete delptr;
        }
        return delvalue;
    }
    int getFront()
    {
        return front->data;
    }
    void display ()
    {
        Node * temp = front;
        while (temp != NULL)
        {
            cout << temp->data<< " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getSize()
    {
        return count;
    }
};

class Stack
{
private:
    Queue obj;
public:
    void push(int value)
    {
        int s = obj.getSize();

        obj.enQuere(value);


        for (int i=0; i<s; i++)
        {
            obj.enQuere(obj.getFront());

            obj.deQueue();
        }
    }
    int top()
    {
        if (obj.isEmpty())
        {
            return -1;
        }
        else
            return obj.getFront();
    }
    void pop()
    {
        if (obj.isEmpty())
            cout << "No elements"<<endl;
        else
            obj.deQueue();
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.pop();
    cout << s.top() << endl;
    s.pop();
    s.push(10);
    s.pop();
    cout << s.top() << endl;
    return 0;
}
