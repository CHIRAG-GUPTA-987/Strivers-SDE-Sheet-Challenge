#include <bits/stdc++.h>
bool sorter(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.second == p2.second)
        return p1.first <= p2.first;
    return p1.second < p2.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    vector<pair<int, int>> dp;
    for (int i = 0; i < start.size(); i++)
        dp.push_back({start[i], finish[i]});
    sort(dp.begin(), dp.end(), sorter);
    int end = 0, ans = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        if (dp[i].first >= end)
        {
            ans++;
            end = dp[i].second;
        }
    }
    return ans;
    // Write your code here.
}