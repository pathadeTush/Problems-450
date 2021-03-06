/*


Rotate doubly Linked List
Easy Accuracy: 55.04% Submissions: 13331 Points: 2

Given a doubly linked list, rotate the linked list counter-clockwise by P nodes. Here P is a given positive integer and is smaller than the count of nodes(N) in a linked list.

Input:
The first line of input contains an integer T denoting the no of test cases. For each test case, the first line of input contains two integers N and P denoting the number of nodes in Linked List and the number of nodes to be rotated respectively.

Output:
For each test case, output the final linked list after the P rotations in it.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= P <= N

Example:
Input:
1
6 2
1 2 3 4 5 6

Output:
3 4 5 6 1 2

Explanation:
Testcase 1: Doubly linked list after rotating 2 nodes is: 3 4 5 6 1 2.

*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next, *prev;

    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
struct node *update(struct node *start, int p);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        struct node *start = NULL;
        struct node *cur = NULL;
        struct node *ptr = NULL;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            ptr = new node(a);
            ptr->data = a;
            ptr->next = NULL;
            ptr->prev = NULL;
            if (start == NULL)
            {
                start = ptr;
                cur = ptr;
            }
            else
            {
                cur->next = ptr;
                ptr->prev = cur;
                cur = ptr;
            }
        }
        struct node *str = update(start, p);
        while (str != NULL)
        {
            cout << str->data << " ";
            str = str->next;
        }
        cout << endl;
    }
}

// } Driver Code Ends
//User function Template for C++

/*
struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

struct node *update(struct node *head, int p)
{
    if (!head || !head->next)
        return head;

    struct node *first = head, *last = head, *newHead = head;

    int size = 1;
    while (last->next)
    {
        last = last->next;
        size++;
    }

    if (p % size == 0)
        return head;

    last->next = first;
    first->prev = last;

    for (int i = 0; i < p; i++)
        newHead = newHead->next;

    newHead->prev->next = nullptr;
    newHead->prev = nullptr;

    return newHead;
}

// { Driver Code Starts.
// } Driver Code Ends