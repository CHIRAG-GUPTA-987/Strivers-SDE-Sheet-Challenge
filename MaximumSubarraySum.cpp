long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long sum = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s > sum)
            sum = s;
        if (s < 0)
            s = 0;
    }
    return sum;
}