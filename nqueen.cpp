#include <bits/stdc++.h>
using namespace std;
int x[20];

bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    cout << "Solution for " << n << " queens:\n";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << ' ';
    }
    cout << "\n";
}

void nQueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) 
                printSolution(n);
            else 
                nQueen(k + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    nQueen(1, n);
    return 0;
}
