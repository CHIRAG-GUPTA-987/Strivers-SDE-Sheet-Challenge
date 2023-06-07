/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; i++)
    {
        vector<int> a;
        a.push_back(intervals[i][0]);
        a.push_back(intervals[i][1]);
        while (i < n - 1 && a[1] >= intervals[i + 1][0])
        {
            i++;
            a[1] = max(a[1], intervals[i][1]);
        }
        ans.push_back(a);
    }
    return ans;
    // Write your code here.
}