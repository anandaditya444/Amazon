

Time - O(Log n)


int kth(int a[], int b[], int n, int m, int k)
{
    // If 1st array is bigger the 2nd array swap the arrays
    if (n > m)
        return kth(b, a, m, n, k);

    // if (n == m)
    //     return k % 2 == 0 ? a[k / 2] : b[k / 2];

    // If size of 1st array becomes zero then simply return kth element
    // in 2nd array
    if (n == 0 && m > 0)
        return b[k - 1];

    // If k becomes one then simply return minimum of the 0th indexes of
    // both the arrays
    if (k == 1)
        return min(a[0], b[0]);

    // Divide the array into two halves
    int i = min(n, k / 2);
    int j = min(m, k / 2);

    // If a[i-1] > b[j-1] then search space reduces to left half of first array
    // and right half of second array
    if (a[i - 1] > b[j - 1])
        return kth(a, b + j, i, m - j, k - j);

    // If a[i-1] < b[j-1] then search space reduces to right half of first array
    // and left half of second array
    return kth(a + i, b, n - i, j, k - i);
}