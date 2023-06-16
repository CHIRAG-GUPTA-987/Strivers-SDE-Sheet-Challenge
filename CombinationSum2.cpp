#include <bits/stdc++.h>
void getSets(int i, const int &n, int &target, const vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (i == n)
        return;
    for (int j = i; j < n; j++)
    {
        while (j != i && j != n && arr[j] == arr[j - 1])
            j++;
        if (j == n)
            return;
        ds.push_back(arr[j]);
        target -= arr[j];
        if (target == 0)
            ans.push_back(ds);
        getSets(j + 1, n, target, arr, ans, ds);
        target += arr[j];
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    getSets(0, n, target, arr, ans, ds);
    return ans;
    // Write your code here.
}
