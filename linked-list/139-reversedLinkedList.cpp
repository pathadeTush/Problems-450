
static struct Node *root, *last;

class Solution
{
public:
    //Function to reverse a linked list.

    // Iterative approach
    // struct Node* reverseList(struct Node *head)
    // {

    //     if(!head || !head->next) return head;

    //     struct Node *prev = nullptr, *Next = nullptr;
    //     struct Node *curr = head;

    //     while(curr){
    //         Next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = Next;
    //     }

    //     head = prev;

    //     return head;

    // }

    // recursive approach
    struct Node *reverseList(struct Node *head)
    {
        if (!head)
            return head;

        root = nullptr;

        reverseList(head->next);
        if (!root)
        {
            root = head;
            last = head;
        }
        else
        {
            root->next = head;
            head->next = nullptr;
            root = head;
        }

        return last;
    }
};