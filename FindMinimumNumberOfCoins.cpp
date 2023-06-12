int findMinimumCoins(int amount)
{
    int denominations[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9, ans = 0;
    while (amount && n--)
    {
        if (denominations[n] <= amount)
        {
            ans += (amount / denominations[n]);
            amount %= denominations[n];
        }
    }
    return ans;
    // Write your code here
}
