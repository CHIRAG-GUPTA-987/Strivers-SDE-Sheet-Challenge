void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if (n == 1 || m == 1)
        return;
    int startRow = 0, endRow = n - 1, startCol = 0, endCol = m - 1;
    while (startRow < endRow && startCol < endCol)
    {
        int temp = mat[startRow][startCol];
        mat[startRow][startCol] = mat[startRow + 1][startCol];
        for (int i = startCol + 1; i <= endCol; i++)
        {
            int temp2 = mat[startRow][i];
            mat[startRow][i] = temp;
            temp = temp2;
        }
        for (int i = startRow + 1; i <= endRow; i++)
        {
            int temp2 = mat[i][endCol];
            mat[i][endCol] = temp;
            temp = temp2;
        }
        for (int i = endCol - 1; i >= startCol; i--)
        {
            int temp2 = mat[endRow][i];
            mat[endRow][i] = temp;
            temp = temp2;
        }
        for (int i = endRow - 1; i > startRow; i--)
        {
            int temp2 = mat[i][startCol];
            mat[i][startCol] = temp;
            temp = temp2;
        }
        startRow++;
        startCol++;
        endRow--;
        endCol--;
    }
    // Write your code here
}