#include <bits/stdc++.h>
// TC => O(3N) , SC = O(1) for set but in worst case it is O(N)
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // optimal => store the elements in the set and just check that the
    // previous one is there or not
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            // nhi mila
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}