
Time - O(N)
Space - O(1)


Node* clone(Node* head)
{
	Node* cur = head;
	Node* temp;

	while (cur != NULL)
	{
		temp = cur->next;

		// Inserting node in between i.e. 1 in between 1 & 2, 2 in between 2 & 3 etc.
		cur->next = newNode(cur->data);
		cur->next->next = temp;
		cur = temp;
	}

	cur = head;

	// adjust the random pointers of the
	// newly added nodes
	while (cur)
	{
		if (cur->next)
		{
			cur->next->random = cur->random ? cur->random->next : cur->random;
		}

		// move to the next newly added node by
		// skipping an original node
		cur = cur->next ? cur->next->next : cur->next;
	}

	Node* original = head, *copy = head->next;

	// save head of copy list
	Node* temp = copy;

	// now separate original and copied lists
	while (original && copy)
	{
		original->next = original->next ? original->next->next : original->next;
		copy->next = copy->next ? copy->next->next : copy->next;

		original = original->next;
		copy = copy->next;
	}
	return temp;
}