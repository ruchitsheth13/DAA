// O(n * 2^n)

#include<bits/stdc++.h>
using namespace std;

void subset_sum(vector<int>& nums, int target, vector<int>& current, int start, int sum) {
    if (sum == target) {
        cout << "Sum = " << target << ": ";
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    if (sum > target) {
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        subset_sum(nums, target, current, i + 1, sum + nums[i]);

        current.pop_back();
    }
}

int main() {
    vector<int> nums = {3, 1, 2, 5, 8};
    int target = 7;
    vector<int> current;
    subset_sum(nums, target, current, 0, 0);
    return 0;
}
