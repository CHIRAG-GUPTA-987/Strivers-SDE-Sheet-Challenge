int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{

    // TIME = O(nlogn) SPACE = O(n) TLE PROBLEM
    // priority_queue<int> q;
    // for(int i=0; i<n; i++) q.push(arr.at(i));
    // int last = q.top(), count = 1, ans=1;
    // q.pop();
    // while(!q.empty()) {
    //     int curr = q.top();
    //     q.pop();
    //     if(curr != last) {
    //         if(curr == last-1) count++;
    //         else count=1;
    //         last = curr;
    //         ans=max(ans, count);
    //     }
    // }
    // return ans;

    unordered_set<int> s;
    int ans = 1;
    for (int i = 0; i < n; i++)
        s.insert(arr.at(i));
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr.at(i) - 1) == s.end())
        {
            int j = arr.at(i) + 1;
            while (s.find(j) != s.end())
                j++;
            ans = max(ans, j - arr.at(i));
        }
    }
    return ans;
    // Write your code here.
}