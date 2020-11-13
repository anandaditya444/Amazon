
Node* detectLoop(Node* head)
{
	if (head == NULL)
		return NULL;
	Node* slow = head;
	Node* fast = head;

	while (slow && fast && fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow != fast)
	{
		cout << "No Loop is there" << endl;
		return NULL;
	}
	slow = head;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}