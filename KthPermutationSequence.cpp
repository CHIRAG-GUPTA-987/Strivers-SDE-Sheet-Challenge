string kthPermutation(int n, int k)
{
    string ans = "";
    int fact = 1;
    vector<char> ds;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        ds.push_back(i + 48);
    }
    ds.push_back(n + 48);
    k--;
    while (n--)
    {
        int index = k / fact;
        ans.push_back(ds[index]);
        ds.erase(ds.begin() + index);
        k = k % fact;
        if (n)
            fact = fact / n;
    }
    return ans;
    // Write your code here.
}
