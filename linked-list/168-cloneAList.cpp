// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

Node *copyList(Node *head);

void append(Node **head_ref, Node **tail_ref, int new_data)
{

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
    }
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res)
{

    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2)
        return false;

    temp1 = head;
    temp2 = res;
    map<Node *, Node *> a;
    while (temp1 != NULL)
    {

        if (temp1 == temp2)
            return false;

        if (temp1->data != temp2->data)
            return false;
        if (temp1->arb != NULL and temp2->arb != NULL)
        {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        }
        else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
        else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1] = temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL)
    {

        if (temp1->arb != NULL and temp2->arb != NULL)
        {
            if (a[temp1->arb] != temp2->arb)
                return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;
    Node *generated_addr = NULL;
    /*reading input stuff*/
    cin >> T;

    while (T--)
    {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;

        cin >> n >> k;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }

        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL)
            {
                count++;
                if (count == a - 1)
                    break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL)
            {
                count++;
                if (count == b - 1)
                    break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n)
            {
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Node *res = copyList(head);

        Node *cloned_addr = res;

        if (validation(head2, res) && validation(head, res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }

    return 0;
} // } Driver Code Ends

//Function to clone a linked list with next and random pointer.
Node *copyList(Node *head)
{
    if (!head)
        return head;

    // create a copy of each node and make each copy's next to node's next and node's next point to its copy
    Node *curr = head;
    while (curr)
    {
        Node *copy = new Node(curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // now make copy's arb pointer points to node's arb->next
    curr = head;
    while (curr)
    {
        Node *copy = curr->next;
        if (curr->arb)
            copy->arb = curr->arb->next;
        else
            copy->arb = nullptr;
        curr = copy->next;
    }

    // Now separate two list from each other by pointing node's next back to it's actual position and at the same time make copy's next point to it's next node's copy
    Node *copyHead = new Node(-1);
    Node *newHead = copyHead;
    curr = head;
    while (curr)
    {
        Node *copy = curr->next;
        copyHead->next = copy;
        curr->next = copy->next;
        curr = curr->next;
        copyHead = copy;
    }

    return newHead->next;
}