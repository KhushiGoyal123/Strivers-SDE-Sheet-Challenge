#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int cnt = 0;
    int xr = 0;

    // xr , count
    map<int, int> mpp;
    mpp[xr]++; //{0, 1}
    for (int i = 0; i < arr.size(); i++)
    {
        xr = xr ^ arr[i];
        int k = xr ^ x;
        cnt += mpp[k];
        mpp[xr]++;
    }
    return cnt;
}