

void nextSmallerElement(int arr[], int n)
{
	stack<int>st;
	st.push(arr[0]);

	for (int i = 1; i < n; i++)
	{
		if (st.empty())
		{
			st.push(arr[i]);
			continue;
		}

		/* if stack is not empty, then
		pop an element from stack.
		If the popped element is greater
		than next, then
		a) print the pair
		b) keep popping while elements are
		smaller and stack is not empty */
		while (!st.empty() && st.top() > arr[i])
		{
			cout << st.top() << " " << arr[i] << endl;
			st.pop();
		}

		/* push next to stack so that we can find
		next smaller for it */
		st.push(arr[i]);
	}
	while (!st.empty())
	{
		cout << st.top() << " " << "-1" << endl;
		st.pop();
	}
}