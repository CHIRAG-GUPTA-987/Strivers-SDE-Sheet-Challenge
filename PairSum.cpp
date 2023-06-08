vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr.at(i) + arr.at(j) > s)
            j--;
        else if (arr.at(i) + arr.at(j) < s)
            i++;
        else
        {
            vector<int> a;
            a.push_back(arr.at(i));
            a.push_back(arr.at(j));
            int c1 = i + 1, c2 = j - 1;
            while (c1 < j && arr.at(i) == arr.at(c1))
                c1++;
            while (i < c2 && arr.at(c2) == arr.at(j))
                c2--;
            int k = 0;
            if (arr.at(i) == arr.at(j))
                k = (c1 - i + 1) * (c1 - i) / 2;
            else
                k = (c1 - i) * (j - c2);
            while (k--)
                ans.push_back(a);
            i = c1, j = c2;
        }
    }
    return ans;
    // Write your code here.
}