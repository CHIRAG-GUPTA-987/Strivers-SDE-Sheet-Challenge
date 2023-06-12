#include <bits/stdc++.h>
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    vector<pair<double, pair<int, int>>> dp;
    for (int i = 0; i < n; i++)
        dp.push_back({(double)(items[i].second) / items[i].first, items[i]});
    sort(dp.begin(), dp.end());
    double ans = 0;
    while (w && n--)
    {
        if (w < dp[n].second.first)
        {
            ans += dp[n].first * w;
            w = 0;
        }
        else
        {
            ans += dp[n].second.second;
            w -= dp[n].second.first;
        }
    }
    return ans;
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
}