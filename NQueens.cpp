bool isSafe(const int &i, const int &j, const int &n, const vector<int> &ds)
{
    // Checking Column
    for (int k = 0; k < n; k++)
        if (ds[k * n + j] == 1)
            return false;

    // Checking Main Diagonal
    for (int k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--)
        if (ds[k * n + l] == 1)
            return false;
    for (int k = i + 1, l = j + 1; k < n && l < n; k++, l++)
        if (ds[k * n + l] == 1)
            return false;

    // Checking Other Diagonal
    for (int k = i - 1, l = j + 1; k >= 0 && l < n; k--, l++)
        if (ds[k * n + l] == 1)
            return false;
    for (int k = i + 1, l = j - 1; k < n && l >= 0; k++, l--)
        if (ds[k * n + l] == 1)
            return false;
}

void placeQueens(int i, const int &n, vector<vector<int>> &ans, vector<int> &ds)
{
    if (i == n)
    {
        ans.push_back(ds);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (isSafe(i, j, n, ds))
        {
            ds[i * n + j] = 1;
            placeQueens(i + 1, n, ans, ds);
            ds[i * n + j] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<int> ds(n * n, 0);
    placeQueens(0, n, ans, ds);
    return ans;
    // Write your code here.
}