


Time Complexity: O(n Log n).
Time Complexity to insert element in min heap is log n. So to insert n element is O( n log n).
Auxiliary Space : O(n).
The Space required to store the elements in Heap is O(n).


void runningMedian(int arr[])
{
	int n = sizeof(arr) / sizeof(arr[0]);

	int med = arr[0];

	// max heap to store the smaller half elements
	priority_queue<int>mx;

	// min heap to store the greater half elements
	priority_queue<int, vector<int>, greater<int>	>mn;

	mx.push(arr[0]);

	// reading elements of stream one by one
	/* At any time we try to make heaps balanced and
		their sizes differ by at-most 1. If heaps are
		balanced,then we declare median as average of
		min_heap_right.top() and max_heap_left.top()
		If heaps are unbalanced,then median is defined
		as the top element of heap of larger size */
	for (int i = 1; i < n; i++)
	{
		int x = arr[i];

		// case1(right side heap has more elements)
		if (mx.size() < mn.size())
		{
			if (x > med)
			{
				mx.push(mn.top());
				mn.pop();
				mn.push(x);
			}
			else
				mx.push(x);
			med = (mx.top() + mn.top()) / 2;
		}

		// case1(left side heap has more elements)
		else if (mx.size() > mn.size())
		{
			if (x < med)
			{
				mn.push(mx.top());
				mx.pop();
				mx.push(x);
			}
			else
				mn.push(x);
			med = (mx.top() + mn.top()) / 2;

		}
		else
		{
			if (x < med)
			{
				mx.push(x);
				med = mx.top();
			}
			else
			{
				mn.push(x);
				med = mn.top();
			}
		}

	}
	cout << med << endl;

}