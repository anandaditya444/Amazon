

Brute Force Approach

Time - O(N*N)
Space - O(1)

int findPlatform(int arr[], int dep[], int n)
{

	// plat_needed indicates number of platforms
	// needed at a time
	int plat_needed = 1, result = 1;
	int i = 1, j = 0;

	// run a nested  loop to find overlap
	for (int i = 0; i < n; i++) {
		// minimum platform
		plat_needed = 1;

		for (int j = i + 1; j < n; j++) {
			// check for overlap
			if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
			        (arr[j] >= arr[i] && arr[j] <= dep[i]))
				plat_needed++;
		}

		// update result
		result = max(result, plat_needed);
	}

	return result;
}




Approach:
We can store the arrival time and departure time in a multmap and take a variable platform_reqd = 0
        As we can see a train arriving we can increment it else decrement it in case of departing and took
		        maximum at every step.
		        Time - O(n)
		        Space - O(n)


		        const int N = 1e3 + 5;
int a[N], d[N];
multimap<int, char>m;

int32_t main()
{
	IOS;
	int t, n;
	cin >> t;
	while (t--)
	{
		m.clear();
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i];
		}
		for (int i = 1; i <= n; i++)
		{
			m.insert({a[i], 'a'});
			m.insert({d[i], 'd'});
		}
		int platforms = 0;
		int ans = 0;
		for (auto x : m)
		{
			if (x.second == 'a')
				platforms++;
			else
				platforms--;
			ans = max(platforms, ans);
		}
		cout << ans << endl;
	}

	return 0;
}
