// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    void splitList(Node *head, Node **l1, Node **l2)
    {
        Node *slow = head, *fast = head->next;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        *l1 = head;
        *l2 = slow->next;
        slow->next = nullptr;
        return;
    }

    Node *merge(Node *l1, Node *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        Node *res = nullptr;
        if (l1->data <= l2->data)
        {
            res = l1;
            l1 = l1->next;
        }
        else
        {
            res = l2;
            l2 = l2->next;
        }
        Node *temp = res;

        while (l1 and l2)
        {
            if (l1->data <= l2->data)
            {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }

        if (l1)
            temp->next = l1;
        else        
            temp->next = l2;

        return res;
    }

    void MergeSort(Node **headref)
    {
        Node *head = *headref;
        if (!head || !head->next)
            return;
        Node *l1, *l2;
        splitList(head, &l1, &l2);
        MergeSort(&l1);
        MergeSort(&l2);

        *headref = merge(l1, l2);
    }

    Node *mergeSort(Node *head)
    {
        MergeSort(&head);
        return head;
    }

    
};

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends