int search(int *arr, int n, int key)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < arr[start])
        {
            if (key < arr[mid] || key >= arr[start])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (key > arr[mid] || key < arr[start])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
    // Write your code here.
}