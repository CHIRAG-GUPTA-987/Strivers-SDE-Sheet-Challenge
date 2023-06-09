class pairSum
{
public:
    int first;
    int second;
    int sum;
    pairSum(int first, int second, int sum)
    {
        this->first = first;
        this->second = second;
        this->sum = sum;
    }
};
bool sorter(pairSum *p1, pairSum *p2)
{
    return p1->sum < p2->sum;
}
bool compare(pairSum *p1, pairSum *p2)
{
    return p1->first != p2->first && p1->first != p2->second && p1->second != p2->first && p1->second != p2->second;
}
string fourSum(vector<int> arr, int target, int n)
{

    // TIME = O(n^3) SPACE = O(1) TLE SOLUTION
    // sort(arr.begin(), arr.end());
    // for(int i=0; i<n-3; i++) {
    //     for(int j=i+1; j<n-2; j++) {
    //         int left = j+1, right = n-1, t=target - (arr.at(i) + arr.at(j));
    //         while(left < right) {
    //             if(arr.at(left) + arr.at(right) == t) return "Yes";
    //             if(arr.at(left) + arr.at(right) < t) {
    //                 left++;
    //                 while(left < right && arr.at(left) == arr.at(left-1)) left++;
    //             }
    //             else {
    //                 right--;
    //                 while(left < right && arr.at(right) == arr.at(right+1)) right--;
    //             }
    //         }
    //         while(j<n-2 && arr.at(j) == arr.at(j+1)) j++;
    //     }
    //     while(i<n-4 && arr.at(i) == arr.at(i+1)) i++;
    // }
    // return "No";

    // TIME = O(n^2logn) SPACE = O(n^2)
    vector<pairSum *> auxArr;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pairSum *p = new pairSum(i, j, arr.at(i) + arr.at(j));
            auxArr.push_back(p);
        }
    }
    sort(auxArr.begin(), auxArr.end(), sorter);
    int left = 0, right = (n * (n - 1) / 2) - 1;
    while (left < right)
    {
        if (auxArr.at(left)->sum + auxArr.at(right)->sum == target && compare(auxArr.at(left), auxArr.at(right)))
            return "Yes";
        if (auxArr.at(left)->sum + auxArr.at(right)->sum > target)
            right--;
        else
            left++;
    }
    return "No";
    // Write your code here.
}
