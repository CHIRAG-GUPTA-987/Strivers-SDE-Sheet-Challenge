vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int i = n - 2;
    for (; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
            break;
    }
    if (i != -1)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (permutation[j] > permutation[i])
            {
                int temp = permutation[i];
                permutation[i] = permutation[j];
                permutation[j] = temp;
                break;
            }
        }
    }
    for (int j = i + 1, k = n - 1; j < k; j++, k--)
    {
        int temp = permutation[k];
        permutation[k] = permutation[j];
        permutation[j] = temp;
    }
    return permutation;
    //  Write your code here.
}