bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int M = mat.size();
    int N = mat[0].size();
    int low = 0;
    int high = N * M - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        int element = mat[mid / N][mid % N];
        if (element == target)
            return true;
        if (element < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    return false;
}