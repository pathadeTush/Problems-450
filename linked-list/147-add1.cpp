// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // function to reverse a list
    Node *reverseList(Node *head)
    {

        if (!head || !head->next)
            return head;

        Node *prev = nullptr, *Next = nullptr;
        Node *curr = head;

        while (curr)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        head = prev;

        return head;
    }

    // function to add 1 to list
    Node *addOne(Node *head)
    {
        // if list is empty
        if (!head)
        {
            head = new Node(1);
            return head;
        }

        // reverse the list
        head = reverseList(head);

        Node *temp = head, *prev = nullptr;

        temp->data++;
        int carry = 0;
        while (temp)
        {
            temp->data = (temp->data + carry) % 10;

            if (temp->data != 0)
                break;
            else
                carry = 1;

            prev = temp;
            temp = temp->next;
        }

        // if all node have 9 data initially
        if (!temp)
            prev->next = new Node(1);

        head = reverseList(head);

        return head;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends