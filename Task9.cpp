#include <iostream>
using namespace std;

const int N = 4;
int grid[N][N] = {
    {1, 0, 0, 4},
    {0, 4, 1, 0},
    {0, 1, 4, 0},
    {4, 0, 0, 1}
};

bool isSafe(int row, int col, int num){
    
    for(int i = 0; i < N; i++){
        if(grid[i][col] == num){
            return false;
        }

        if(grid[row][i] == num){
            return false;
        }
    }

    int startRow = (row / 2) * 2;
    int startCol = (col / 2) * 2;

     for (int i = startRow; i < startRow + 2; i++) {
        for (int j = startCol; j < startCol + 2; j++) {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoko(int row, int col){
    if(row == N)
    return true;

    int nextRow = row;
    int nextCol = col + 1;

    if(nextCol == N){
        nextRow++;
        nextCol = 0;
    }

    if(grid[row][col] != 0)
        return solveSudoko(nextRow, nextCol);

    for(int num = 1; num <= 4; num++){
        if(isSafe(row, col, num)){
            grid[row][col] = num;

            if(solveSudoko(nextRow, nextCol))
            return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    if (solveSudoko(0, 0)) {
        cout << "Solved Sudoko:\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}