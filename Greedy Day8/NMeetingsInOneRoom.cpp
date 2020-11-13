

Approach:
sort according to the finishing time and then check for intervals

Time - O(n*Logn)
    Space - O(n)




    const int N = 105;

typedef struct timings
{
    int start, end, pos;
};
timings arr[N];

int32_t main()
{
    IOS;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].start;
            arr[i].pos = i;
        }
        for (int i = 1; i <= n; i++)
            cin >> arr[i].end;
        sort(arr + 1, arr + n + 1, [&](timings & a, timings & b)
        {
            if (a.end == b.end)
                return a.start < b.start;
            return a.end < b.end;

        });
        cout << arr[1].pos << " ";
        timings prev = arr[1];
        for (int i = 2; i <= n; i++)
        {
            if (arr[i].start >= prev.end)
            {
                cout << arr[i].pos << " ";
                prev = arr[i];
            }
        }
        cout << endl;
    }



    return 0;
}