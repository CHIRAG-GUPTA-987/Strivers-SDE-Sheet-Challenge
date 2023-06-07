bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int begin = 0, end = mat.size() - 1;
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        if (mat[mid][0] == target)
            return true;
        if (mat[mid][0] > target)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    if (end < 0)
        return false;
    int cbegin = 0, cend = mat.at(end).size() - 1;
    while (cbegin <= cend)
    {
        int mid = (cbegin + cend) / 2;
        if (mat[end][mid] == target)
            return true;
        if (mat[end][mid] > target)
            cend = mid - 1;
        else
            cbegin = mid + 1;
    }
    return false;
}