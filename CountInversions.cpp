long long merge(long long *arr, int start, int mid, int end)
{
    vector<long long> temp;
    int i = start, j = mid + 1;
    long long ans = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            ans += (mid - i + 1);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    i = start;
    while (i <= end)
    {
        arr[i] = temp.at(i - start);
        i++;
    }
    return ans;
}
long long mergeSort(long long *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        long long a1 = mergeSort(arr, start, mid);
        long long a2 = mergeSort(arr, mid + 1, end);
        return a1 + a2 + merge(arr, start, mid, end);
    }
    return 0;
}
long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n - 1);
    // Write your code here.
}