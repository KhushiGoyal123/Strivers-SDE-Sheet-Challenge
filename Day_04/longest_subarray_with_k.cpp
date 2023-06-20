#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{
    // brute force => compute the subarrays and calculate sum in the next loop
    // running from j=i to n => O(n^2)

    // better approach => hashing
    map<int, int> prefSum;
    int maxLen = 0;
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (prefSum.find(rem) != prefSum.end())
        {
            int len = i - prefSum[rem];
            maxLen = max(maxLen, len);
        }
        if (prefSum.find(sum) == prefSum.end())
        {
            prefSum[sum] = i;
        }
    }

    return maxLen;
}