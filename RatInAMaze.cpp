#include <bits/stdc++.h>
void findPaths(vector<vector<int> > &maze, int n, int i, int j, vector<vector<int> > &ans, vector<int> &a)
{
    if (i == n || j == n)
        return;
    if (i < 0 || j < 0)
        return;
    if (maze[i][j] == 0)
        return;
    if (i == n - 1 && j == n - 1)
    {
        a[i * n + j] = 1;
        ans.push_back(a);
        a[i * n + j] = 0;
        return;
    }
    maze[i][j] = 0;
    a[i * n + j] = 1;
    findPaths(maze, n, i - 1, j, ans, a);
    findPaths(maze, n, i, j - 1, ans, a);
    findPaths(maze, n, i + 1, j, ans, a);
    findPaths(maze, n, i, j + 1, ans, a);
    a[i * n + j] = 0;
    maze[i][j] = 1;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n)
{
    vector<vector<int> > ans;
    vector<int> a(n * n, 0);
    findPaths(maze, n, 0, 0, ans, a);
    return ans;
    // Write your code here.
}