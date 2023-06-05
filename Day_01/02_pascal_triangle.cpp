#include <bits/stdc++.h>
#include <vector>

long long nCr(int n, int r)
{
    long long res = -1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
// for finding element at some row and at specified column => call nCr(n-1, r-1) => TC - O(r)

// to print any particular row n => TC - O(N)
/*
int ans = 1;
print(ans);
for(int i=1; i<row; i++){
  ans = ans * (n-i);
  ans = ans / i;
  print(ans);
}
*/

vector<long long int> generateRow(int row)
{
    long long ans = 1;
    vector<long long int> ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// current problem is to print the whole pascal triangle till nth row => O(n^2) for optimal solution
vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> ans;
    for (int i = 1; i <= n; i++)
    {
        // vector<long long int> temp = generateRow(i);
        ans.push_back(generateRow(i));
    }
    return ans;
}