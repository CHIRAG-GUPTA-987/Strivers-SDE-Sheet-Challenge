void setZeros(vector<vector<int>> &matrix)
{
    // USING EXTRA SPACE OF O(n), TIME = O(n*m)
    // vector<int> row(matrix.size(), 1), col(matrix.at(0).size(), 1);
    // for(int i=0; i<matrix.size(); i++) {
    // 	for(int j=0; j<matrix[i].size(); j++) {
    // 		if(matrix.at(i).at(j) == 0) {
    // 			row[i] = 0;
    // 			col[j] = 0;
    // 		}
    // 	}
    // }
    // for(int i=0; i<matrix.size(); i++) {
    // 	for(int j=0; j<matrix[0].size(); j++) {
    // 		if(row.at(i) == 0 || col.at(j) == 0) {
    // 			matrix[i][j] = 0;
    // 		}
    // 	}d
    // }

    // SPACE = O(1), TIME = O(n*m)
    int c0 = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix.at(i).at(j) == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    c0 = 0;
            }
        }
    }
    for (int i = matrix.size() - 1; i >= 1; i--)
    {
        for (int j = matrix[0].size() - 1; j >= 1; j--)
        {
            if (matrix.at(i).at(0) == 0 || matrix.at(0).at(j) == 0)
                matrix[i][j] = 0;
        }
    }
    for (int i = 1; i < matrix[0].size(); i++)
    {
        if (matrix.at(0).at(0) == 0)
            matrix[0][i] = 0;
    }
    if (c0 == 0)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
    // Write your code here.
}