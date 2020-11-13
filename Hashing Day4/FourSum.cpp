if (n < 4)
{
	cout << 0 << endl;
	continue;
}
sort(arr + 1, arr + n + 1);
int a = 1, b = 2, c = n - 1, d = n;
int flag = 0;
while (a < b && b < c && c < d)
{
	int sum = arr[a] + arr[b] + arr[c] + arr[d];
	if (sum == x)
	{
		cout << 1 << endl;
		flag = 1;
		break;
	}
	else if (sum < x)
	{
		if (b < c - 1)
			b++;
		else
			a++;
	}
	else
	{
		if (c > b + 1)
			c--;
		else
			d--;
	}
}
if (flag)
	continue;
else
	cout << 0 << endl;