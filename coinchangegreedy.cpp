#include <bits/stdc++.h>
using namespace std;

int coinChangeGreedy(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    int count = 0;
    for (int i = 0; i < coins.size() && amount > 0; i++) {
        int coin = coins[i];
        int numCoins = amount / coin;
        count += numCoins;
        amount -= numCoins * coin;
    }
    return (amount == 0) ? count : -1;
}

int main() {
    vector<int> coins = {1, 5, 10, 25};
    int amount = 47;
    int minCoins = coinChangeGreedy(coins, amount);
    if (minCoins == -1) {
        cout << "No solution exists." << endl;
    } else {
        cout << "Minimum number of coins required: " << minCoins << endl;
    }
    return 0;
}
