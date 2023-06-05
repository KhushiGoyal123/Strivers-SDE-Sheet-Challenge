#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int cost = prices[0];

    for (int i = 0; i < n; i++)
    {
        int profit = prices[i] - cost;
        maxProfit = max(maxProfit, profit);
        cost = min(cost, prices[i]);
    }

    return maxProfit;
}