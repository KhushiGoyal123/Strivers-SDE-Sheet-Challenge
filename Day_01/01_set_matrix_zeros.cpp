#include <bits/stdc++.h>

// brute force -> TC-(n*m)*(n*m)+(n*m) => O(n^3 approx)

void markRow(vector<vector<int>> &matrix, int i, int col)
{
    for (int j = 0; j < col; j++)
    {
        if (matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}
void markCol(vector<vector<int>> &matrix, int j, int row)
{
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}

void setZeros(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, i, col);
                markCol(matrix, j, row);
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

#include <bits/stdc++.h>

// better solution => O(2*n*m) => O(n^2 approx) and SC => O(n)+O(m)

void setZeros(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int extraRow[row] = {0};
    int extraCol[col] = {0};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                extraRow[i] = 1;
                extraCol[j] = 1;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (extraRow[i] || extraCol[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

#include <bits/stdc++.h>

// optimal solution => O(n*m) => O(n^2 approx) and SC => O(1)

void setZeros(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int col0 = 1;
    // extraRow = matrix[..][0]
    // extraCol = matrix[0][..]

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark the ith row
                matrix[i][0] = 0;
                // mark the jth col
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col and row
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < col; j++)
            matrix[0][j] = 0;
    }
    if (col0 == 0)
    {
        for (int i = 0; i < row; i++)
            matrix[i][0] = 0;
    }
}