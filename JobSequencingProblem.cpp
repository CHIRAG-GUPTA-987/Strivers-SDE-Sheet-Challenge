#include <bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(jobs.begin(), jobs.end());
    for (int i = 0; i < jobs.size(); i++)
    {
        if (pq.empty())
            pq.push(jobs[i][1]);
        else if (pq.size() >= jobs[i][0] && jobs[i][1] > pq.top())
        {
            pq.pop();
            pq.push(jobs[i][1]);
        }
        else if (pq.size() < jobs[i][0])
            pq.push(jobs[i][1]);
    }
    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    return ans;
    // Write your code here
}