#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // naive => generate all substrings (similar to kadane's algo)
    // O(N^2), SC = O(N) for hashset

    // better approach => two pointer with set
    // O(2N) TC since each character is visited twice by both left and right,
    // SC = O(N) for set
    // if a character is present in the set, remove it and move left by one step
    // and check if all repeating characters are removed
    // and then compute the len of the substring which will be
    // right - left + 1

    // now for optimal approach
    // diff will be instead of set we can use map which will store the character
    // as well as index of every character and also it is important to update the
    // index of repeating character's last occurence
    vector<int> mpp(256, -1);
    // we can also take map<char,int>
    int n = input.size();
    int len = 0;
    int left = 0, right = 0;
    while (right < n)
    {
        if (mpp[input[right]] != -1)
            left = max(mpp[input[right]] + 1, left);
        mpp[input[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}