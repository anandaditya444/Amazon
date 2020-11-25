
We can implement a stack by using array and linkedlist.

For Array:
Pros: Easy to implement. Memory is saved as pointers are not involved.
Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.

For Linkedlist:
Pros: The linked list implementation of stack can grow and shrink according to the needs at runtime.
Cons: Requires extra memory due to involvement of pointers.


All operations are O(1).

const int N = 1e5 + 5;

class stack {
	int top;
public:
	int st[N];
	stack ()
	{
		top = -1;
	}
	void push(int x);
	void pop();
	int peek();
	bool isEmpty();
};

void stack::push(int x)
{
	if (top < N)
	{
		a[++top] = x;
	}
	else
	{
		cout << "Overflow";
	}
}

void stack::pop()
{
	if (top == -1)
	{
		cout << "Underflow";
	}
	else
	{
		top--;
	}
}

int stack::peek()
{
	if (top == -1)
		cout << "Stack is empty";
	else
		return a[top];
}

bool stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}