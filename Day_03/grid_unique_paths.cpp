#include <bits/stdc++.h>
int uniquePaths(int m, int n)
{
    int N = n - 1 + m - 1;
    int r = n - 1;
    double ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = ans * (N - r + i) / i;
    }
    return int(ans);
}