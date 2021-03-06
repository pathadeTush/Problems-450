class Solution
{
public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        if (!head || !head->next)
            return;

        Node *slow = nullptr, *fast = nullptr, *loopNode = nullptr;

        slow = head;             // slow will move forward by 1 unit
        fast = head->next->next; // fast will move forward by 2 unit

        bool loopFound = false;

        while (fast)
        {
            if (slow == fast)
            {
                loopFound = true; // if fast == slow implies there is a cycle
                break;
            }

            slow = slow->next;
            if (fast->next)
            {
                fast = fast->next;
                if (fast->next)
                    fast = fast->next;
                else
                    return;
            }
            else
                return;
        }

        if (!loopFound)
            return;

        Node *ptr1 = slow, *ptr2 = slow;
        int k = 1;
        while (ptr1->next != ptr2)
        {
            ptr1 = ptr1->next;
            k++;
        }

        ptr1 = head;
        ptr2 = head;

        for (int i = 0; i < k; i++)
            ptr2 = ptr2->next;

        while (ptr2 != ptr1)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // Get pointer to the last node
        while (ptr2->next != ptr1)
            ptr2 = ptr2->next;

        /* Set the next node of the loop ending node
          to fix the loop */
        ptr2->next = NULL;

        return;
    }
};

Method 2 (Better Solution)  

    This method is also dependent on Floyd’s Cycle detection algorithm.
    Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
    Count the number of nodes in loop. Let the count be k.
    Fix one pointer to the head and another to a kth node from the head.
    Move both pointers at the same pace, they will meet at loop starting node.
    Get a pointer to the last node of the loop and make next of it as NULL.

Thanks to WgpShashank for suggesting this method.
Below image is a dry run of ‘remove loop’ function in the code : 

Below is the implementation of the above approach:

#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* Function to remove loop. */
void removeLoop(struct Node*, struct Node*);
 
/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
 
    /* Return 0 to indicate that there is no loop*/
    return 0;
}
 
/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;
 
    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
 
    // Fix one pointer to head
    ptr1 = head;
 
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
 
    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
 
    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
 
    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}
 
/* Function to print linked list */
void printList(struct Node* node)
{
    // Print the list after loop removal
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// Driver Code
int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}
 
// This code has been contributed by Striver

Output: 

Linked List after removing loop 
50 20 15 4 10 

Method 3 (Optimized Method 2: Without Counting Nodes in Loop) 
We do not need to count number of nodes in Loop. After detecting the loop, if we start slow pointer from head and move both slow and fast pointers at same speed until fast don’t meet, they would meet at the beginning of the loop.

How does this work? 
Let slow and fast meet at some point after Floyd’s Cycle finding algorithm. Below diagram shows the situation when cycle is found.

LinkedListCycle


We can conclude below from above diagram 

Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time

From above equation, we can conclude below 

    m + k = (x-2y)*n

Which means m+k is a multiple of n. 
Thus we can write, m + k = i*n or m = i*n - k.
Hence, distance moved by slow pointer: m, is equal to distance moved by fast pointer:
i*n - k or (i-1)*n + n - k (cover the loop completely i-1 times and start from n-k).

So if we start moving both pointers again at same speed such that one pointer (say slow) begins from head node of linked list and other pointer (say fast) begins from meeting point. When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made also moved m steps as they are now moving same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No because slow pointer enters the cycle first time after m steps. 

// C++ program to detect and remove loop
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
// Function to detect and remove loop
// in a linked list that may contain loop
void detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return;
 
    Node *slow = head, *fast = head;
 
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
           
        // this check is needed when slow
        // and fast both meet at the head of the LL
          // eg: 1->2->3->4->5 and then
        // 5->next = 1 i.e the head of the LL
          if(slow == fast) {
              while(fast->next != slow) fast = fast->next;
        }
          else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
 
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}
 
/* Driver program to test above function*/
int main()
{
    Node* head = newNode(50);
    head->next = head;
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    return 0;
}

Output:

Linked List after removing loop 
50 20 15 4 10 