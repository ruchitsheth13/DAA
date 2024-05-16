// O(n^log7) = O(n^2.87)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int z[2][2];
    int i, j;
    int m1, m2, m3, m4, m5, m6, m7;
    int x[2][2] = {
        {1, 2},
        {3, 4}
    };
    int y[2][2] = {
        {5, 6}, 
        {7, 8}
    };
    cout << "The first matrix is: ";
    for(i = 0; i < 2; i++) {
        cout << endl;
        for(j = 0; j < 2; j++) {
            cout << x[i][j] << " ";
        }
    }
    cout << "\nThe second matrix is: ";
    for(i = 0; i < 2; i++) {
        cout << endl;
        for(j = 0; j < 2; j++) {
            cout << y[i][j] << " ";
        }
    }
    m1 = (x[0][0] + x[1][1]) * (y[0][0] + y[1][1]);
    m2 = (x[1][0] + x[1][1]) * y[0][0];
    m3 = x[0][0] * (y[0][1] - y[1][1]);
    m4 = x[1][1] * (y[1][0] - y[0][0]);
    m5 = (x[0][0] + x[0][1]) * y[1][1];
    m6 = (x[1][0] - x[0][0]) * (y[0][0] + y[0][1]);
    m7 = (x[0][1] - x[1][1]) * (y[1][0] + y[1][1]);

    z[0][0] = m1 + m4 - m5 + m7;
    z[0][1] = m3 + m5;
    z[1][0] = m2 + m4;
    z[1][1] = m1 - m2 + m3 + m6;

    cout << "\nProduct after using Strassen's mulitplication: ";
    for(i = 0; i < 2; i++) {
        cout << endl;
        for(j = 0; j < 2; j++) {
            cout << z[i][j] << " ";
        }
    }    
    return 0;
}
