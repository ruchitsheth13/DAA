#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int quantity[1001];

int coinChange(int coins[], int n, int sum) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (i == 0) {
                dp[i][j] = INT_MAX;
            } else if (j == 0) {
                dp[i][j] = 0;
            } else if (coins[i-1] <= j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                if (dp[i][j] == dp[i-1][j]) {
                    quantity[j] = 0;
                } else {
                    quantity[j] = quantity[j-coins[i-1]] + 1;
                }
            } else {
                dp[i][j] = dp[i-1][j];
                quantity[j] = 0;
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int coins[] = {1, 2, 3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 5;
    cout << "Minimum number of coins required: " << coinChange(coins, n, sum) << endl;
    cout << "Combination of coins: ";
    for (int i = 0; i <= sum; i++) {
        if (quantity[i] != 0) {
            cout << i << ": " << quantity[i] << " coin(s)."<< endl;
        }
    }
    cout << endl;
    return 0;
}
