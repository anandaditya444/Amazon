
Time - O(n*logn)
Space - O(n)

typedef struct dtype
{
	int val, weight;
};
const int N = 105;
dtype arr[N];

int32_t main()
{
	IOS;
	int t, n, w;
	cin >> t;
	while (t--)
	{
		cin >> n >> w;
		for (int i = 0; i < n; i++)
			cin >> arr[i].val >> arr[i].weight;
		sort(arr, arr + n, [&](dtype & a, dtype & b)
		{
			return (double)(a.val / a.weight) > (double)(b.val / b.weight);
		});
		int cur_weight = 0;
		double ans_value = 0;
		for (int i = 0; i < n; i++)
		{
			if (cur_weight + arr[i].weight <= w)
			{
				cur_weight += arr[i].weight;
				ans_value += arr[i].val;
			}
			else
			{
				int remain = w - cur_weight;
				ans_value += (double)(arr[i].val / arr[i].weight) * (double)remain;
				break;
			}
		}
		cout << fixed << setprecision(2) << ans_value << endl;
	}

	return 0;
}