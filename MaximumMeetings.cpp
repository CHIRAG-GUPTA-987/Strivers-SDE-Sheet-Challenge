bool sorter(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
{
    if (p1.second.second == p2.second.second)
        return p1.first < p2.first;
    return p1.second.second < p2.second.second;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<int> ans;
    vector<pair<int, pair<int, int>>> dp;
    for (int i = 0; i < start.size(); i++)
        dp.push_back({i + 1, {start[i], end[i]}});
    sort(dp.begin(), dp.end(), sorter);
    int e = -1;
    for (int i = 0; i < dp.size(); i++)
    {
        if (dp[i].second.first > e)
        {
            ans.push_back(dp[i].first);
            e = dp[i].second.second;
        }
    }
    return ans;
    // Write your code here.
}