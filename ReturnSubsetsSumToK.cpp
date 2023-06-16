void getSubsets(int i, const int &n, int k, const vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (i == n)
        return;
    for (int j = i; j < n; j++)
    {
        ds.push_back(arr[j]);
        k -= arr[j];
        if (k == 0)
            ans.push_back(ds);
        getSubsets(j + 1, n, k, arr, ans, ds);
        k += arr[j];
        ds.pop_back();
    }
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    getSubsets(0, n, k, arr, ans, ds);
    return ans;
    // Write your code here.
}