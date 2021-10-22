
/*


Add two numbers represented by linked lists
Easy Accuracy: 30.12% Submissions: 99609 Points: 2

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).

Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).

Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M))

Constraints:
1 <= N, M <= 5000

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

    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        if (!first and second)
            return second; // if first list is empty
        if (first and !second)
            return first; // if second list is empty

        Node *sum = nullptr;

        // reverse the both list to add 1 by 1 data from last to first
        first = reverseList(first);
        second = reverseList(second);

        // initialize our sum list
        sum = new Node(first->data + second->data);

        first = first->next;
        second = second->next;

        int carry = 0;
        // check if carry present
        if (sum->data > 9)
        {
            carry = 1;
            sum->data = (sum->data) % 10;
        }

        // add 1 by 1 data of first and second to the sum list until both list are not empty
        Node *temp = sum;
        while (first and second)
        {
            temp->next = new Node(first->data + second->data + carry);

            if (temp->next->data > 9)
            {
                carry = 1;
                temp->next->data = (temp->next->data) % 10;
            }
            else
            {
                carry = 0;
            }
            first = first->next;
            second = second->next;
            temp = temp->next;
        }

        // if first list is not empty yet
        while (first)
        {
            temp->next = new Node(first->data + carry);

            if (temp->next->data > 9)
            {
                carry = 1;
                temp->next->data = (temp->next->data) % 10;
            }
            else
            {
                carry = 0;
            }

            first = first->next;
            temp = temp->next;
        }

        // if second list is not empty yet
        while (second)
        {
            temp->next = new Node(second->data + carry);

            if (temp->next->data > 9)
            {
                carry = 1;
                temp->next->data = (temp->next->data) % 10;
            }
            else
            {
                carry = 0;
            }

            second = second->next;
            temp = temp->next;
        }

        // check if there is carry from last node
        if (carry)
        {
            temp->next = new Node(1);
        }

        // now reverse our sum list and return it
        sum = reverseList(sum);

        return sum;
    }
};
