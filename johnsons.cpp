#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    vector<int> processingTimes;
};

bool cmp(const Job& a, const Job& b) {
    return a.processingTimes[0] < b.processingTimes[0];
}

void johnsonsAlgorithm(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), cmp);

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        sequence[i] = i;
    }
    for (int k = 1; k < n; k++) {
        int minTime = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < n - k; i++) {
            int time = jobs[sequence[i]].processingTimes[k] + jobs[sequence[i+1]].processingTimes[k-1];
            if (time < minTime) {
                minTime = time;
                minIndex = i;
            }
        }
        swap(sequence[minIndex], sequence[minIndex+1]);
    }

    cout << "Optimal sequence: ";
    for (int i = 0; i < n; i++) {
        cout << jobs[sequence[i]].id << " ";
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = {
        {1, {3, 5, 2}},
        {2, {2, 4, 3}},
        {3, {4, 2, 1}}
    };
    johnsonsAlgorithm(jobs, 3);
    return 0;
}
