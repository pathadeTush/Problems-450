// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
public:
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

    //Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int k)
    {
        if (k == 0)
            return nullptr;

        Node *newHead = arr[0];

        for (int i = 1; i < k; i++)
            newHead = merge(newHead, arr[i]);

        return newHead;
    }
};

// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}
// } Driver Code Ends