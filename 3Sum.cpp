vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i != 0 && arr[i] == arr.at(i - 1))
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == K)
            {
                ans.push_back(vector<int>({arr[i], arr[j], arr[k]}));
                j++, k--;
                while (j < k && arr[j] == arr.at(j - 1))
                    j++;
                while (j < k && arr[k] == arr.at(k + 1))
                    k--;
            }
            else if (sum > K)
                k--;
            else
                j++;
        }
    }
    return ans;
    // Write your code here.
}