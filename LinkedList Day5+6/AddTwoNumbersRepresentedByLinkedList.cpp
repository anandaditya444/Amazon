Node* reverse(Node* head)
{
    Node* cur = head;
    Node* prev = NULL;

    while (cur != NULL)
    {
        Node* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node* l1 = reverse(first);
    Node* l2 = reverse(second);
    Node* ans = new Node(0);
    Node* head = ans;
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;
        ans->next = new Node(sum % 10);
        ans = ans->next;
        carry = sum / 10;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry > 0)
        ans->next = new Node(carry);
    Node* result = head->next;
    return reverse(result);
}



Node* reverse(Node* head)
{
    Node* cur = head, *prev = NULL;

    while (cur != NULL)
    {
        Node* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}


Node* addTwoLists(Node* first, Node* second)
{
    Node* l1 = reverse(first);
    Node* l2 = reverse(second);

    Node* ans = new Node(0);
    Node* head = ans;

    int carry = 0;

    while (l1 != NULL || l2 != NULL)
    {
        int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;
        ans->next = new Node(sum % 10);
        ans = ans->next;
        carry = sum / 10;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry > 0)
    {
        ans->next = new Node(carry);
    }
    return reverse(head->next);
}