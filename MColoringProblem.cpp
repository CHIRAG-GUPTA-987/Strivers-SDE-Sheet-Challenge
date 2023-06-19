#include <bits/stdc++.h>
bool isColorable(const int &curr, const vector<vector<int>> &mat, const int col, const vector<int> &isColored)
{
    for (int i = 0; i < mat[curr].size(); i++)
        if (mat[curr][i] == 1 && isColored[i] == col)
            return false;
    return true;
}
bool color(int curr, const vector<vector<int>> &mat, const int &m, vector<int> &isColored)
{
    if (curr == mat.size())
        return true;
    for (int i = 0; i < m; i++)
    {
        if (isColorable(curr, mat, i, isColored))
        {
            isColored[curr] = i;
            if (color(curr + 1, mat, m, isColored))
                return true;
            isColored[curr] = -1;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> isColored(n, -1);
    return color(0, mat, m, isColored) ? "YES" : "NO";
    // Write your code here
}