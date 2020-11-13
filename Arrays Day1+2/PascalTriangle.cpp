

int32_t main()
{
    IOS;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int> >v;
        v.push_back({1});
        v.push_back({1, 1});
        for (int i = 2; i < n; i++)
        {
            vector<int>x = v[i - 1];
            vector<int>res;
            res.push_back(x[0]);
            for (int i = 1; i < x.size(); i++)
            {
                res.push_back(x[i] + x[i - 1]);
            }
            res.push_back(x.back());
            v.push_back(res);
        }
        for (auto x : v[n - 1])
            cout << x << " ";
        cout << endl;
    }



    return 0;
}