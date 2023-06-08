vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int el = arr.at(i), count = 1;
        while (i < n - 1 && arr.at(i + 1) == el)
        {
            i++;
            count++;
        }
        if (count > n / 3)
            ans.push_back(el);
    }
    return ans;
    // Write your code here.
}