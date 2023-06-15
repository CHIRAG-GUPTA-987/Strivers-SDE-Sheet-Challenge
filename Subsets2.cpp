#include <bits/stdc++.h>
void generateSets(int i, const int &n, const vector<int> &arr, vector<vector<int>> &ans, vector<int> ds)
{
    if (i == n)
        return;
    for (int j = i; j < n; j++)
    {
        while (j != n && j != i && arr[j] == arr[j - 1])
            j++;
        if (j == n)
            return;
        ds.push_back(arr[j]);
        ans.push_back(ds);
        generateSets(j + 1, n, arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    ans.push_back(vector<int>());
    sort(arr.begin(), arr.end());
    generateSets(0, n, arr, ans, vector<int>());
    return ans;
    // Write your code here.
}