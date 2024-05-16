#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cout << "Enter size of array: ";
    cin >> N;
    int arr1[N];
    int max = INT_MIN, min = INT_MAX;
    for(int i = 0; i < N; i++) {
        cin >> arr1[i];
        if(arr1[i] > max)
            max = arr1[i];
        if(arr1[i] < min)
            min = arr1[i];
    }
    cout << "The max and min elements in the array are: " << max  << " " << min << endl;
}
