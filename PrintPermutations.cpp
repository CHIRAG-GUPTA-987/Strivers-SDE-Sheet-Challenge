#include <bits/stdc++.h>
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
void getPerms(string &s, const int &n, int i, vector<string> &ans)
{
    if (i == n)
    {
        ans.push_back(s);
        return;
    }
    for (int j = i; j < n; j++)
    {
        swap(s[i], s[j]);
        getPerms(s, n, i + 1, ans);
        swap(s[i], s[j]);
    }
}
vector<string> findPermutations(string &s)
{
    vector<string> ans;
    int n = s.size();
    vector<bool> isVisited(n, false);
    getPerms(s, n, 0, ans);
    return ans;
    // Write your code here.
}