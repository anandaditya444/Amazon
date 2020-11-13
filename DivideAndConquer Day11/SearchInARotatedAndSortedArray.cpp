

Time - O(LogN)
Space - O(1)

const int N = 1e7 + 5;
int a[N];
int t, n, target;

int binsearch(int lo, int hi)
{
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (a[mid] == target)
            return mid;
        if (a[lo] <= a[mid])
        {
            if (target >= a[lo] && target <= a[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        else if (a[mid] <= a[hi])
        {
            if (target >= a[mid] && target <= a[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    return -1;
}
