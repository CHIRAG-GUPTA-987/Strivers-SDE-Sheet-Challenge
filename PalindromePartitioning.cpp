#include <bits/stdc++.h>
bool isPalindrome(const string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void getPalindrome(int i, const int &n, vector<string> &ds, vector<vector<string>> &ans, const string &s)
{
    if (i == n)
    {
        ans.push_back(ds);
        return;
    }
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(s, i, j))
        {
            ds.push_back(s.substr(i, j - i + 1));
            getPalindrome(j + 1, n, ds, ans, s);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    getPalindrome(0, s.size(), ds, ans, s);
    return ans;
    // Write your code here.
}