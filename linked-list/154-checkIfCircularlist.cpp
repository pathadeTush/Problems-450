/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
    if (!head)
        return false;

    Node *temp = head->next;

    while (temp and temp != head)
        temp = temp->next;

    if (!temp)
        return false;
    return true;
}