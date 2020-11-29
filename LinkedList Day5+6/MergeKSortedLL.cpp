
Time - O((N*K)*Log(K))
Space - O(K)

struct compare()
{
	bool operator()(Node * a, Node * b) {
		return a->data > b->data;
	}
}

struct Node* mergeKSortedLL(Node* arr[], int K)
{
	priority_queue<Node*, vector<Node*>, compare>pq;
	for (int i = 0; i < K; i++)
		if (arr[i] != NULL)
			pq.push(arr[i]);

	Node* dummy = newNode(0);
	Node* ans = dummy;
	while (!pq.empty())
	{
		Node* f = pq.top();
		pq.pop();
		dummy->next = f;
		dummy = dummy->next;

		if (f->next)
			pq.push(f->next);
	}
	return ans->next;
}