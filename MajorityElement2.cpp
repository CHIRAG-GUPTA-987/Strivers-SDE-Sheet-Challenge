vector<int> majorityElementII(vector<int> &arr)
{

    // TIME = O(nlogn) SPACE = O(1)
    // vector<int> ans;
    // sort(arr.begin(), arr.end());
    // int n=arr.size();
    // for(int i=0; i<n; i++) {
    //     int el = arr.at(i), count=1;
    //     while(i<n-1 && arr.at(i+1) == el) {
    //         i++;
    //         count++;
    //     }
    //     if(count > n/3) ans.push_back(el);
    // }
    // return ans;

    // TIME = O(n) SPACE = O(1)
    vector<int> ans;
    int el1 = INT_MIN, el2 = INT_MIN, cnt1 = 0, cnt2 = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != arr.at(i))
            el1 = arr.at(i);
        else if (cnt2 == 0 && el1 != arr.at(i))
            el2 = arr.at(i);
        if (el1 == arr.at(i))
            cnt1 += 1;
        else if (el2 == arr.at(i))
            cnt2 += 1;
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == arr.at(i))
            cnt1++;
        if (el2 == arr.at(i))
            cnt2++;
    }
    if (cnt1 > n / 3)
        ans.push_back(el1);
    if (cnt2 > n / 3)
        ans.push_back(el2);
    return ans;
    // Write your code here.
}