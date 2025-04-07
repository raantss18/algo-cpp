#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 6;

bool is_valid(const vector<vector<int>>& grid, int row, int col, int num) {
    for (int j = 0; j < SIZE; j++) {
        if (grid[row][j] == num) return false;
    }
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) return false;
    }
    int start_row = (row / 2) * 2;
    int start_col = (col / 3) * 3;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[start_row + i][start_col + j] == num) return false;
        }
    }
    return true;
}

bool find_empty(const vector<vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solve(vector<vector<int>>& grid) {
    int row, col;
    if (!find_empty(grid, row, col)) {
        return true;
    }
    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

bool is_sudoku_solvable(const vector<vector<int>>& grid) {
    vector<vector<int>> copy = grid;
    return solve(copy);
}

void print_grid(const vector<vector<int>>& grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> input_grid() {
    vector<vector<int>> grid(SIZE, vector<int>(SIZE));
    cout << "Entrez la grille 6x6 ligne par ligne (utilisez 0 pour les cases vides) :\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Ligne " << i + 1 << ": ";
        for (int j = 0; j < SIZE; j++) {
            cin >> grid[i][j];
        }
    }
    return grid;
}

int main() {
    vector<vector<int>> grid = input_grid();

    cout << "Grille initiale:" << endl;
    print_grid(grid);

    if (is_sudoku_solvable(grid)) {
        cout << "Grille résolue:" << endl;
        solve(grid);
        print_grid(grid);
    } else {
        cout << "Grille non résoluble." << endl;
    }

    return 0;
}
