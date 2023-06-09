#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &nums1, vector<int> &nums2, int m, int n)
{
    vector<int> v;
    int k = m + n - 1, i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] < nums2[j])
            nums1[k--] = nums2[j--];
        else
            nums1[k--] = nums1[i--];
    }
    while (j >= 0)
        nums1[k--] = nums2[j--];

    for (auto i : nums1)
    {
        v.push_back(i);
    }
    return v;
}