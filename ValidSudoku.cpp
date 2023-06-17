bool isPlaceAble(const int &i, const int &j, const int &k, const int matrix[9][9])
{
    // Row and Column Check
    for (int l = 0; l < 9; l++)
    {
        if (matrix[i][l] == k)
            return false;
        if (matrix[l][j] == k)
            return false;
    }
    // Block Check
    int curr1 = i % 3, curr2 = j % 3;
    int starti = i - curr1, startj = j - curr2;
    int endi = i + (3 - curr1), endj = j + (3 - curr2);
    for (int m = starti; m < endi; m++)
    {
        for (int n = startj; n < endj; n++)
        {
            if (matrix[m][n] == k)
                return false;
        }
    }
    return true;
}
bool isPossible(int i, int j, int matrix[9][9])
{
    if (i == 9)
        return true;
    if (matrix[i][j] == 0)
    {
        for (int k = 1; k <= 9; k++)
        {
            if (isPlaceAble(i, j, k, matrix))
            {
                matrix[i][j] = k;
                bool flag = false;
                if (j == 8)
                {
                    if (isPossible(i + 1, 0, matrix))
                        flag = true;
                }
                else if (isPossible(i, j + 1, matrix))
                    flag = true;
                matrix[i][j] = 0;
                if (flag)
                    return true;
            }
        }
        return false;
    }
    else
    {
        if (j == 8)
            return isPossible(i + 1, 0, matrix);
        else
            return isPossible(i, j + 1, matrix);
    }
}
bool isItSudoku(int matrix[9][9])
{
    return isPossible(0, 0, matrix);
    // Write your code here.
}
