
#include <bits/stdc++.h>
using namespace std;

// Function to compute maximum value for given capacity
int knapsack(int capacity, vector<int> &values, vector<int> &weights) {

    // dp[w] stores max value achievable with weight limit w
    vector<int> dp(capacity + 1, 0);

    // Go through each item
    for (int item = 0; item < weights.size(); item++) {
        // Loop backwards to avoid overwriting useful previous states
        for (int currCap = capacity; currCap >= weights[item]; currCap--) {
            dp[currCap] = max(dp[currCap], dp[currCap - weights[item]] + values[item]);
        }
    }

    return dp[capacity];
}
