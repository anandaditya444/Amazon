
Time Complexity of Enqueue : O(1)
Time Complexity of Dequeue : O(n)

const int N = 1e5 + 5;

class Queue {
	int front, rear;
public:
	int queue[N];
	Queue {
		front = rear = 0;
	}
	void enqueue(int x);
	void dequeue();
	int front();
};

void Queue::enqueue(int x)
{
	if (rear < N)
		queue[rear++] = x;
	else
		cout << "Queue is full";
}

void Queue::dequeue()
{
	if (front == rear)
		cout << "Queue is empty";
	else
	{
		// queue[front] = -1;
		// front++;

		for (int i = 0; i < rear - 1; i++)
			queue[i] = queue[i + 1];
		rear--;
	}
}

int Queue: front()
{
	if (front == rear)
		cout << "Queue is empty";
	else
		return queue[front];
}

