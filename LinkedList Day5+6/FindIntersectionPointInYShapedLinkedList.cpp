n : length of first length_of_LL
m : length of second length_of_LL

Time - O(M + N)
Space - O(1)

Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the difference of counts d = abs(c1 – c2)
                                 Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have
                                 equal no of nodes
                                 Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common
                                         node is done by comparing the address of the nodes





                                         Time - O(n + m)
                                         Space - O(n)

                                         int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<Node*>s;
    Node* cur = head1;
    while (cur != NULL)
    {
        s.insert(cur);
        cur = cur->next;
    }
    cur = head2;
    while (cur != NULL)
    {
        if (s.count(cur))
            return cur->data;
        cur = cur->next;
    }
    return -1;
}








Time - O(n + m)
Space - O(1)


int length_of_LL(Node* head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
int intersection_point(Node* head1, Node* head2, int d)
{
    Node* cur = head1;
    while (d--)
    {
        cur = cur->next;
    }
    head1 = cur;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int l1 = length_of_LL(head1);
    int l2 = length_of_LL(head2);

    int diff = max(l1, l2) - min(l1, l2);
    if (l1 > l2)
    {
        return intersection_point(head1, head2, diff);
    }
    else
    {
        return intersection_point(head2, head1, diff);
    }
    return -1;
}