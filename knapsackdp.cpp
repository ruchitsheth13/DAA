#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int profit[], int n) {
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
            if (wt[i - 1] <= w)
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + profit[i - 1]);
        }
    }
    return dp[W];
}

int main() {
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << "The max value is: " << knapSack(W, weight, profit, n);
    return 0;
}
