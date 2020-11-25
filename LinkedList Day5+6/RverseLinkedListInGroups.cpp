

Time Complexity: O(n).

Auxiliary Space: O(n / k).
For each Linked List of size n, n / k or (n / k) + 1 calls will be made during the recursion.


Node* reverseInGroups(Node* head, int K)
{
	Node* cur = head;
	Node* temp = NULL;
	Node* prev = NULL;
	int cnt = 0;


	// Reverse first K nodes
	while (cur != NULL && cnt < K)
	{
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
		cnt++;
	}


	/* next is now a pointer to (k+1)th node
	Recursively call for the list starting from current.
	And make rest of the list as next of first node */
	if (temp != NULL)
		head->next = reverseInGroups(temp, K);

	/* prev is new head of the input list */
	return prev;
}