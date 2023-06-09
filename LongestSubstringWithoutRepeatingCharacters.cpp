int uniqueSubstrings(string input)
{
    int ans = 0, count = 0, start = 0;
    unordered_map<char, int> umap;
    for (int i = 0; i < input.size(); i++)
    {
        if (umap[input[i]])
        {
            if (count >= i - umap[input[i]] + 1)
                count = i - umap[input[i]] + 1;
            else
            {
                count++;
                ans = max(ans, count);
            }
            umap[input[i]] = i + 1;
        }
        else
        {
            umap[input[i]] = i + 1;
            count++;
            ans = max(ans, count);
            // cout<<input[i]<<" "<<umap[input[i]]<<" "<<count<<endl;
        }
    }
    return ans;
    // Write your code here
}