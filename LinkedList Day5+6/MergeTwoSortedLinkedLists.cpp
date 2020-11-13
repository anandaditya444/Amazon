
Time - O(n)

Node* sortedMerge(Node* head_A, Node* head_B)
{
    if (head_A == NULL && head_B == NULL)
        return NULL;
    if (head_A == NULL)
        return head_B;
    if (head_B == NULL)
        return head_A;
    if (head_A->data < head_B->data)
        head_A->next = sortedMerge(head_A->next, head_B);
    else
        head_B->next =  sortedMerge(head_A, head_B->next);
    return head_A->data < head_B->data ? head_A : head_B;
}