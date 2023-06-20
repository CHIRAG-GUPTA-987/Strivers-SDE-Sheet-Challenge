#include <bits/stdc++.h>
bool isContained(const string &str, const vector<string> &dictionary)
{
    for (int i = 0; i < dictionary.size(); i++)
        if (str == dictionary[i])
            return true;
    return false;
}
void generateStrings(int start, int end, const string &s, const vector<string> &dictionary, string a, vector<string> &ans)
{
    string str = s.substr(start, end - start);
    if (end == s.size())
    {
        if (isContained(str, dictionary))
        {
            a += str;
            ans.push_back(a);
        }
        return;
    }
    generateStrings(start, end + 1, s, dictionary, a, ans);
    if (isContained(str, dictionary))
    {
        a += (str + " ");
        generateStrings(end, end + 1, s, dictionary, a, ans);
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    generateStrings(0, 1, s, dictionary, "", ans);
    return ans;
    // Write your code here
}