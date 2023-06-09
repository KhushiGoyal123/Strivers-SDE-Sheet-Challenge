// optimized
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{

    // time complexity -> O(n)
    // space complexity -> O(1)
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}


// brute force
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }
    return 0;
}
