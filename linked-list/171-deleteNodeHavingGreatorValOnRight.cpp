// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

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
    Node *reverseList(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *curr = head, *prev = nullptr, *Next = nullptr;

        while (curr)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }

    Node *compute(Node *head)
    {
        if (!head || !head->next)
            return head;

        head = reverseList(head);

        int maxVal = INT_MIN;

        Node *curr = head, *prev = head;
        head = nullptr;

        while (curr)
        {
            if (curr->data < maxVal)
            {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
            else
            {
                if (!head)
                    head = curr;
                maxVal = max(maxVal, curr->data);
                prev = curr;
                curr = curr->next;
            }
        }

        head = reverseList(head);
        return head;
    }
}
}
;

/*

10 20 30 40 50 60

*/

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}
// } Driver Code Ends