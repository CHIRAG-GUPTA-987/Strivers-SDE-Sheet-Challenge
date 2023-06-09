int subarraysXor(vector<int> &arr, int x)
{
    int ans = 0, X = 0;
    unordered_map<int, int> umap;
    umap[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        X = X ^ arr.at(i);
        if (umap[X ^ x])
            ans += umap[X ^ x];
        umap[X]++;
    }
    return ans;
    //    Write your code here.
}