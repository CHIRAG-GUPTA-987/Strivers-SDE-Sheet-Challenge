#include <bits/stdc++.h>
void getSet(int n, vector<int> &arr, set<vector<int>> &s, vector<int> &temp)
{
    if (n == -1)
    {
        s.insert(temp);
        return;
    }
    getSet(n - 1, arr, s, temp);
    temp.push_back(arr[n]);
    getSet(n - 1, arr, s, temp);
    temp.pop_back();
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end(), greater<int>());
    set<vector<int>> s;
    vector<int> temp;
    getSet(n - 1, arr, s, temp);
    for (auto itr : s)
        ans.push_back(itr);
    return ans;
    // Write your code here.
}