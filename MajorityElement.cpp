int findMajorityElement(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int el = arr[i], count = 1;
        while (i < n - 1 && el == arr[i + 1])
        {
            i++;
            count++;
        }
        if (count > n / 2)
            return el;
    }
    return -1;
    // Write your code here.
}