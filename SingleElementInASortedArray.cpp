int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        bool flag = true;
        if (mid != 0 && arr[mid] == arr[mid - 1])
        {
            flag = false;
            if (mid % 2)
                start = mid + 1;
            else
                end = mid - 1;
        }
        if (mid != n - 1 && arr[mid] == arr[mid + 1])
        {
            flag = false;
            if (mid % 2)
                end = mid - 1;
            else
                start = mid + 1;
        }
        if (flag)
            return arr[mid];
    }
    return -1;
    // Write your code here
}