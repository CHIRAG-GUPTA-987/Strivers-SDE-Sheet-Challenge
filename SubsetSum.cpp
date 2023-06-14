#include <bits/stdc++.h>
void getSum(vector<int> &nums, vector<int> &ans, int n, int sum = 0)
{
    if (n == -1)
    {
        ans.push_back(sum);
        return;
    }
    getSum(nums, ans, n - 1, sum);
    getSum(nums, ans, n - 1, sum + nums[n]);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    getSum(num, ans, num.size() - 1);
    sort(ans.begin(), ans.end());
    return ans;
    // Write your code here.
}