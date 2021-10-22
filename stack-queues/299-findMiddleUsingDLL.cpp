#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *prev, *next;

    node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

class Stack
{
private:
    int size;
    node *head, *tail, *mid;

public:
    Stack()
    {
        size = 0;
        head = new node(-1);
        tail = new node(-1);
        mid = new node(-1);
        mid->next = head;
        head->next = tail;
        tail->prev = head;
    }

    void push(int data)
    {
        node *newnode = new node(data);
        //cout << newnode->data << " " << data << endl;
        newnode->next = tail;
        tail->prev->next = newnode;
        tail->prev = newnode;
        size++;
        // odd
        if (size & 1)
            mid = mid->next;
        return;
    }

    int pop()
    {
        if (head->next == tail)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        node *temp = tail->prev;
        if(temp->prev)
        cout << temp->prev->data << endl;
else
    cout << "null" << endl;

// temp->prev->next = tail;
// tail->prev = temp->prev;
// size--;
// // even
// if (!(size & 1))
//     mid = mid->prev;
// int data = temp->data;
// free(temp);
return temp->data;
    }

    int getMid()
    {
        if (head->next == tail)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return mid->data;
    }

    int deleteMid()
    {
        if (head->next == tail)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        node *temp = mid;
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev;
        size--;
        // odd
        if ((size & 1))
            mid = mid->next;
        int data = temp->data;
        free(temp);
        return data;
    }

    void traverse(){
        node *pointer = head->next;
        while(pointer != tail){
            cout << pointer->data << " ";
            pointer = pointer->next;
        }
        cout << endl;
        return;
    }
};

int main()
{
    Stack *s = new Stack();

    s->push(11);
    s->push(22);
    s->push(33);
    s->push(44);
    s->push(55);
    s->push(66);
    s->push(77);

    s->traverse();

     cout << "Item popped is " << s->pop() << endl;
    // cout << "Item popped is " << s->pop() << endl;
    // cout << "Item popped is " << s->pop() << endl;
    // cout << "Middle Element is " << s->getMid() << endl;
    // cout << "Deleted Middle Element is " << s->deleteMid() << endl;
    // cout << "Middle Element is " << s->getMid() << endl;

    return 0;
}