
Time - O(n)
Space - O(n)

int maxLen(int A[], int n)
{
    int ans = 0, flag = 0;
    unordered_map<int, vector<int> >m;
    m[A[0]].push_back(0);
    for (int i = 1; i < n; i++)
    {
        A[i] += A[i - 1];
        m[A[i]].push_back(i);
    }

    for (auto x : m)
    {
        if (x.first == 0)
        {
            ans = max(ans, m[x.first].back() + 1);
            continue;
        }
        if (m[x.first].size() > 1)
        {
            ans = max(ans, m[x.first].back() - m[x.first][0]);
        }
    }
    return ans;
}




Time - O(n*n)
Space - O(1)

int maxLen(int A[], int n)
{
    int ans = 0, flag = 0;
    for (int i = 1; i < n; i++)
    {
        A[i] += A[i - 1];
        if (A[i] == 0)
        {
            flag = 1;
            ans = max(ans, i + 1);
        }
    }
    if (flag)
        return ans;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            int diff = A[i] - A[j - 1];
            if (diff == 0)
                ans = max(ans, i - j + 1);
        }
    }
    return ans;
}