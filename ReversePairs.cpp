int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1, ans = 0;
    while (i <= mid && j <= high)
    {
        if (arr.at(i) <= 2 * arr.at(j))
            i++;
        else
        {
            ans += (mid - i + 1);
            j++;
        }
    }
    i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr.at(i) <= arr.at(j))
        {
            temp.push_back(arr.at(i));
            i++;
        }
        else
        {
            temp.push_back(arr.at(j));
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr.at(i));
        i++;
    }
    while (j <= high)
    {
        temp.push_back(arr.at(j));
        j++;
    }
    for (i = low; i <= high; i++)
        arr[i] = temp.at(i - low);
    return ans;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        return mergeSort(arr, low, mid) + mergeSort(arr, mid + 1, high) + merge(arr, low, mid, high);
    }
    return 0;
}
int reversePairs(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
    // Write your code here.
}