int findMajorityElement(int arr[], int n)
{

    // TIME = O(nlogn) SPACE = O(1)
    // sort(arr, arr+n);
    // for(int i=0; i<n; i++) {
    // 	int el = arr[i], count = 1;
    // 	while(i<n-1 && el == arr[i+1]){
    // 		i++;
    // 		count++;
    // 	}
    // 	if(count > n/2) return el;
    // }
    // return -1;

    // TIME = O(n) SPACE = O(1) USING MOORE'S VOTING ALGORITHM
    int element = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            element = arr[i];
        if (element == arr[i])
            count++;
        else
            count--;
    }
    count = 0;
    for (int i = 0; i < n; i++)
        if (element == arr[i])
            count++;
    return count > n / 2 ? element : -1;
    // Write your code here.
}