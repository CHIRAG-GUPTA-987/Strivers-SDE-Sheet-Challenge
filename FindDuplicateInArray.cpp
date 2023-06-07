int findDuplicate(vector<int> &arr, int n)
{

    // HASHING
    //  vector<bool> isVisited(n, false);
    //  for(int i=0; i<n; i++) {
    //  	if(isVisited.at(arr.at(i))) return arr.at(i);
    //  	isVisited[arr.at(i)] = true;
    //  }
    //  return 1;

    // LINKED LIST APPROACH
    int slow = arr[0], fast = arr[0];
    while (true)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
        if (slow == fast)
            break;
    }
    fast = arr[0];
    while (fast != slow)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return fast;
    // Write your code here.
}