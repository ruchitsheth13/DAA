#include <stdio.h>
#include <limits.h>

int printOptimalParenthesis(int s[][6], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[n][n]; 
    int s[n][n]; 
	int i, l, k;
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (l = 2; l < n; l++) {
        for (i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);

    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n - 1);
    printf("\n");
}

int main() {
    int p[] = { 1, 5, 4, 3, 2, 1 }; 
    int n = sizeof(p) / sizeof(p[0]);
    matrixChainOrder(p, n);
    return 0;
}
