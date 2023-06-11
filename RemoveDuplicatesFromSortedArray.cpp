int removeDuplicates(vector<int> &arr, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (i < n - 1 && arr[i] == arr[i + 1])
            i++;
        ans++;
    }
    return ans;
    // Write your code here.
}