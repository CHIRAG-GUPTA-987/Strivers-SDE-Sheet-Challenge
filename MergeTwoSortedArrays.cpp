vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
            i++;
        else
        {
            for (int k = m; k > i; k--)
            {
                arr1[k] = arr1[k - 1];
            }
            arr1[i] = arr2[j];
            m++;
            i++;
            j++;
        }
    }
    while (j < n)
    {
        arr1[i] = arr2[j];
        i++;
        j++;
    }
    return arr1;
    // Write your code here.
}