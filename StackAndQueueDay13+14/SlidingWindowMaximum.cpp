
Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.


Time - O(N)
	It seems more than O(n) at first look. It can be observed that every element of array is added and removed at
	most once. So there are total 2n operations.
	Space - O(K)

Algorithm :

	Create a deque to store k elements.
	Run a loop and insert first k elements in the deque. While inserting the element if the element at the
	back of the queue is smaller than the current element remove all those elements and then insert the element.
	Now, run a loop from k to end of the array.
	Print the front element of the array
	Remove the element from the front of the queue if they are out of the current window.
		Insert the next element in the deque. While inserting the element if the element at the back of the
			queue is smaller than the current element remove all those elements and then insert the element.
			Print the maximum element of the last window.




			void slidingWindowMaximum(int a[], int n, int k)
			{
				deque<int>dq;
				int i = 1;
				for (i = 1; i <= k; i++)
				{
					while (!dq.empty() && a[dq.back()] <= a[i])
						dq.pop_back();
					dq.push_back(i);
				}
				while (i <= n)
				{
					cout << a[dq.front()] << " ";
					while (!dq.empty() && dq.front() <= i - k)
						dq.pop_front();
					while (!dq.empty() && a[dq.back()] <= a[i])
						dq.pop_back();
					dq.push_back(i++);
				}
				cout << a[dq.front()] << endl;
			}