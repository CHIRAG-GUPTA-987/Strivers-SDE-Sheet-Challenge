vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> ans;
    if (n == 0)
        return ans;
    vector<long long int> a(1, 1);
    ans.push_back(a);
    for (int i = 1; i < n; i++)
    {
        vector<long long int> a(i + 1, 1);
        for (int j = 0; j < i - 1; j++)
        {
            a[j + 1] = ans.at(i - 1).at(j) + ans.at(i - 1).at(j + 1);
        }
        ans.push_back(a);
    }
    return ans;
    // Write your code here.
}