
Time - O(n)

struct Node* reverseList(struct Node *head)
{
  struct Node* cur = head;
  struct Node* prev = NULL;
  while (cur != NULL)
  {
    struct Node* temp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = temp;
  }
  return prev;
}