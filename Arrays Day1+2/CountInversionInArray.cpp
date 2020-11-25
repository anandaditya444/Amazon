
Using Merge Sort
Time - O(n*logn) as every level need a full traversal and there are logn levels
Space - O(n)

const int N = 1e7 + 5;
int a[N];

int merge(int* a, int* temp, int start, int mid, int end)
{
    int i = start, j = mid, k = start;
    int inv_count = 0;
    while (i < mid && j <= end)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            inv_count += mid - i;
        }
    }
    while (i < mid)
        temp[k++] = a[i++];
    while (j <= end)
        temp[k++] = a[j++];
    for (int i = start; i <= end; i++)
        a[i] = temp[i];
    return inv_count;
}

int mergesort(int* a, int* temp, int start, int end)
{
    int inv_count = 0;
    if (start < end)
    {
        int mid = (start + end) / 2;

        inv_count += mergesort(a, temp, start, mid);
        inv_count += mergesort(a, temp, mid + 1, end);

        inv_count += merge(a, temp, start, mid + 1, end);
    }
    return inv_count;
}





int merge(int arr[], int start, int mid, int end)
{
    int i = start, j = mid, k = start;
    int temp[N];

    int inv_cnt = 0;
    while (i < mid && j <= end)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            inv_cnt = mid - i;
        }
    }
    while (i < mid)
        temp[k++] = a[i++];
    while (j <= end)
        temp[k++] = a[j++];
    for (int k = start; k <= end; k++)
        a[i] = temp[i];
}


int mergeSort(int arr[], int start, int end)
{
    int inv_cnt = 0;
    if (start < end)
    {
        int mid = (start + end) / 2;
        inv_cnt += mergeSort(arr, start, mid);
        inv_cnt += mergeSort(arr, mid + 1, end);
        inv_cnt += merge(arr, start, mid + 1, end);
    }
    return inv_cnt;
}