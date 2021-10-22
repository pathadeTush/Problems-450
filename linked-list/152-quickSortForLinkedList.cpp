// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node **head_ref, int new_data)
{
    /* allocate node */
    struct node *new_node = new node(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {

        cin >> n;
        n = n - 1;
        cin >> x;
        node *temp, *head = new node(x);
        temp = head;
        while (n--)
        {
            cin >> x;
            temp->next = new node(x);
            temp = temp->next;
        }

        quickSort(&head);

        printList(head);
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return 0;
} // } Driver Code Ends

/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

void partition(struct node *head, struct node **l1, struct node **l2)
{
    if (!head || !head->next)
        return;

    struct node *pivot = head;
    // choose pivot as a last node
    while (pivot->next)
        pivot = pivot->next;

    struct node *j = head;
    struct node *i = head;
    struct node *prev = head; // pointer pointing previous to i

    while (j->next)
    {
        // move all smaller node towards start
        if (j->data < pivot->data)
        {
            int temp = j->data;
            j->data = i->data;
            i->data = temp;
            prev = i;
            i = i->next;
        }
        j = j->next;
    }

    // swap the ith node with pivot node
    // now i is the pivot index
    // so make l1 points to the list till i-1 or till prev
    // and that of l2 to i to null
    int temp = i->data;
    i->data = pivot->data;
    pivot->data = temp;

    *l1 = head;
    *l2 = prev->next;
    prev->next = nullptr;

    return;
}

//you have to complete this function
void quickSort(struct node **headRef)
{

    struct node *head = *headRef;

    if (!head || !head->next)
        return;

    struct node *l1 = nullptr, *l2 = nullptr;

    partition(head, &l1, &l2);

    quickSort(&l1);
    quickSort(&l2);

    // join to lists l1 and l2 and make head point to l1
    head = l1;
    struct node *temp = l1;
    while (temp->next)
        temp = temp->next;
    temp->next = l2;
    return;
}