// O(n*logn)

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

void printJobScheduling(vector<Job> jobs, int n) {
    sort(jobs.begin(), jobs.end(), cmp);
    vector<int> result(n, -1);
    vector<int> slot(n, -1);
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                result[j] = i;
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Following is maximum profit sequence of jobs:\n";
    for (int i = 0; i < n; i++) {
        if (result[i] != -1)
            cout << "Job " << jobs[result[i]].id << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    int n = jobs.size();
    printJobScheduling(jobs, n);
    return 0;
}
