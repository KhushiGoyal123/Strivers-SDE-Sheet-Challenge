#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    int count = 0;
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            element = arr[i];
            continue;
        }
        if (arr[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (element == arr[i])
        {
            count++;
        }
    }
    return count > n / 2 ? element : -1;
}
