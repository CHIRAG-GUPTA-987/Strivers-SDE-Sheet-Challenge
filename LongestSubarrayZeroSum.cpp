int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size(), sum = 0, ans = 0;
    unordered_map<int, int> umap;
    umap[0] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr.at(i);
        if (umap[sum])
            ans = max(ans, i - umap[sum]);
        else
            umap[sum] = i;
    }
    return ans;
    // Write your code here
}