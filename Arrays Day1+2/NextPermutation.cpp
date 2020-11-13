
int32_t main()
{
    IOS;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = n - 1;
        while (i >= 1 && a[i - 1] >= a[i])
            i--;
        if (i == 0)
            sort(a, a + n);
        else
        {
            int cur = a[i - 1];
            int ele = 1e9;
            int idx;
            for (int pos = i; pos < n; pos++)
            {
                if (a[pos] >= cur)
                {
                    int x = min(ele, a[pos]);
                    if (x <= ele)
                    {
                        ele = x;
                        idx = pos;
                    }
                }
            }
            swap(a[i - 1], a[idx]);
            sort(a + i, a + n);
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }



    return 0;
}