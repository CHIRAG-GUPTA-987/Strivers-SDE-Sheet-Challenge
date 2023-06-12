int lss(const vector<int> &arr, int n, int k, bool isLastPicked)
{
    if (n == 0)
        return 0;
    int pick = 0, notPick = 0;
    if (arr[n - 1] == 1)
        pick = 1 + lss(arr, n - 1, k, true);
    else if (arr[n - 1] == 0 && k > 0)
        pick = 1 + lss(arr, n - 1, k - 1, true);
    if (!isLastPicked)
        notPick = lss(arr, n - 1, k, false);
    return max(pick, notPick);
}

int lssMem(const vector<int> &arr, int n, int k, bool isLastPicked, vector<vector<vector<int>>> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n][k][isLastPicked] != -1)
        return dp[n][k][isLastPicked];
    int pick = 0, notPick = 0;
    if (arr[n - 1] == 1)
        pick = 1 + lssMem(arr, n - 1, k, true, dp);
    else if (arr[n - 1] == 0 && k > 0)
        pick = 1 + lssMem(arr, n - 1, k - 1, true, dp);
    if (!isLastPicked)
        notPick = lssMem(arr, n - 1, k, false, dp);
    return dp[n][k][isLastPicked] = max(pick, notPick);
}

int longestSubSeg(vector<int> &arr, int n, int k)
{

    // MEMOIZATION
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
    // return lssMem(arr, n, k, false, dp);

    // TABULATION
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
    // for(int i=1; i<=n; i++) {
    //     for(int j=0; j<=k; j++) {
    //         int pick = 0, notPick = 0;
    //         if(arr[i-1] == 1) pick = 1 + dp[i-1][j][1];
    //         else if(arr[i-1] == 0 && j > 0) pick = 1 + dp[i-1][j-1][1];
    //         notPick = dp[i-1][j][0];
    //         dp[i][j][0] = max(pick, notPick);
    //         dp[i][j][1] = pick;
    //     }
    // }
    // return dp[n][k][0];

    // SPACE OPTIMIZATION
    // vector<vector<int>> dp(k+1, vector<int>(2, 0));
    // for(int i=1; i<=n; i++) {
    //     vector<vector<int>> temp(k+1, vector<int>(2, 0));
    //     for(int j=0; j<=k; j++) {
    //         int pick = 0, notPick = 0;
    //         if(arr[i-1] == 1) pick = 1 + dp[j][1];
    //         else if(arr[i-1] == 0 && j > 0) pick = 1 + dp[j-1][1];
    //         notPick = dp[j][0];
    //         temp[j][0] = max(pick, notPick);
    //         temp[j][1] = pick;
    //     }
    //     dp = temp;
    // }
    // return dp[k][0];

    // TWO POINTER ALGORITHM
    int i = 0, j = 0, ans = 0;
    while (j < n)
    {
        if (arr[j] == 1)
        {
            j++;
            ans = max(ans, j - i);
        }
        else
        {
            if (k > 0)
            {
                k--;
                j++;
                ans = max(ans, j - i);
            }
            else
            {
                if (arr[i] == 1)
                    i++;
                else
                {
                    i++;
                    k++;
                }
            }
        }
    }
    return ans;
    // Write your code here.
}
