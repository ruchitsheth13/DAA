#include <bits/stdc++.h>
using namespace std;

bool is_solvable(vector<int>& puzzle) {
    int inversions = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = i + 1; j < 15; j++) {
            if (puzzle[i] > puzzle[j] && puzzle[i] != 0) {
                inversions++;
            }
        }
    }
    return inversions % 2 == 0;
}

vector<int> find_solution(vector<int>& puzzle) {
    int depth = 0;
    vector<vector<int>> path;
    path.push_back(puzzle);
    while (true) {
        int blank = -1;
        for (int i = 0; i < 15; i++) {
            if (puzzle[i] == 0) {
                blank = i;
                break;
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        bool solved = true;
        for (int i = 0; i < 15; i++) {
            if (i != blank && puzzle[i] == i + 1) {
                solved = false;
                break;
            }
        }
        if (solved) {
            return path[0];
        }
        for (int i = 0; i < 4; i++) {
            int x = blank % 4 + dx[i];
            int y = blank / 4 + dy[i];
            if (x >= 0 && x < 4 && y >= 0 && y < 4) {
                int next_blank = y * 4 + x;
                swap(puzzle[blank], puzzle[next_blank]);
                path.push_back(puzzle);
                if (find_solution(puzzle) != vector<int>()) {
                    return path[0];
                }
                path.pop_back();
                swap(puzzle[blank], puzzle[next_blank]);
            }
        }
        path.pop_back();
        depth++;
    }
}

int main() {
    vector<int> puzzle = {2, 10, 14, 5, 7, 0, 9, 6, 11, 13, 3, 1, 12, 4, 8};
    if (is_solvable(puzzle)) {
        vector<int> solution = find_solution(puzzle);
        for (int move : solution) {
            cout << move << " ";
        }
    } else {
        cout << "No solution." << endl;
    }
    return 0;
}
