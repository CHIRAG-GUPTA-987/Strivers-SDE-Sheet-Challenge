bool sorter(pair<bool, int> &p1, pair<bool, int> &p2)
{
    if (p1.second == p2.second)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
int calculateMinPatforms(int at[], int dt[], int n)
{
    int ans = 0, count = 0;
    vector<pair<bool, int>> dp;
    for (int i = 0; i < n; i++)
    {
        dp.push_back({true, at[i]});
        dp.push_back({false, dt[i]});
    }
    sort(dp.begin(), dp.end(), sorter);
    for (int i = 0; i < n; i++)
    {
        if (dp[i].first == true)
        {
            count++;
            ans = max(ans, count);
        }
        else
            count--;
    }
    return ans;
    // Write your code here.
}