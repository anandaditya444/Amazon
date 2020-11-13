
Time - O(n)
Space - O(1)


int length_of_ll(Node* head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

Node* rotate(Node* head, int k)
{
    int len = length_of_ll(head);
    if (k > len)
        return NULL;
    Node* cur = head;
    Node* prev = NULL;
    while (cur != NULL && k--)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    if (cur == NULL)
        return head;
    Node* res = cur;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = head;
    return res;
}