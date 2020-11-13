

const int N = 1e7 + 5;
int a[N];

void nextLargerElement(int a[], int n)
{
	unordered_map<int, int>m;
	stack<int>st;
	st.push(a[1]);
	for (int i = 2; i <= n; i++)
	{
		if (st.empty())
		{
			st.push(a[i]);
			continue;
		}

		/* if stack is not empty, then
		pop an element from stack.
		If the popped element is smaller
		than next, then
		a) print the pair
		b) keep popping while elements are
		smaller and stack is not empty */
		while (!st.empty() && st.top() < a[i])
		{
			m[st.top()] = a[i];
			st.pop();
		}

		/* push next to stack so that we can find
		next smaller for it */
		st.push(a[i]);
	}
	while (!st.empty())
	{
		m[st.top()] = -1;
		st.pop();
	}
	for (int i = 1; i <= n; i++)
		cout << m[a[i]] << " ";
	cout << endl;
}