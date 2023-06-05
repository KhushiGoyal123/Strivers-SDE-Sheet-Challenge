#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // brute force :- algo :- O(n! * n) => very high
    //  1. generate all permutation
    //  2. apply linear search
    //  3. print next permutation

    // Better approach :- inbuilt STL function
    next_permutation(permutation.begin(), permutation.end());
    return permutation;
}

#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // optimal solution => TC - O(3N) in worst case

    // 1. longest prefix match
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    // 2. someone smallest but greater than index
    for (int i = n - 1; i > ind; i--)
    {
        if (permutation[i] > permutation[ind])
        {
            swap(permutation[i], permutation[ind]);
            break;
        }
    }

    // 3. try to place remaining in sorted order
    // rev(permutation, ind+1, n-1);
    reverse(permutation.begin() + ind + 1, permutation.end());

    return permutation;
}