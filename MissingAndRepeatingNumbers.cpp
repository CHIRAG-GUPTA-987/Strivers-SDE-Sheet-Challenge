pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> ans;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = x ^ (i + 1);
        x = x ^ arr[i];
    }
    int setBit = 0, y = x, z = x;
    while (!(y & 1))
    {
        y = y >> 1;
        setBit++;
    }
    for (int i = 0; i < n; i++)
    {
        if (((i + 1) >> setBit) & 1)
            x = x ^ (i + 1);
        if ((arr[i] >> setBit) & 1)
            x = x ^ arr[i];
    }
    int i = 0;
    for (; i < n; i++)
    {
        if (x == arr[i])
        {
            ans = {z ^ x, x};
            break;
        }
    }
    if (i == n)
        ans = {x, z ^ x};
    return ans;
    // Write your code here
}