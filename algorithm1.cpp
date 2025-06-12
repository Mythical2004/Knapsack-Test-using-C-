#include <bits/stdc++.h>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // If the current item's weight is less than or equal to the current capacity
            if (wt[i - 1] <= w) {
                // Maximize value by either including or excluding the current item
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                // Exclude the current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right cell contains the maximum value achievable
    return dp[n][W];
}



