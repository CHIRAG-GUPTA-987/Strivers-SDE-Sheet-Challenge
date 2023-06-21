int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2.0;
        double div = m;
        for (int i = 0; i < n - 1; i++)
        {
            div = div / mid;
        }
        if (mid == div)
            return mid;
        if (mid > div)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
    // Write your code here.
}