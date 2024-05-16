#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activity_selection(Activity arr[], int n) {
    sort(arr, arr + n, compare);
    int i = 0;
    cout << "Following activities are selected :" << endl;
    cout << arr[i].start << " " << arr[i].finish << endl;
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << arr[j].start << " " << arr[j].finish << endl;
            i = j;
        }
    }
}

int main() {
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    activity_selection(arr, n);
    return 0;
}
