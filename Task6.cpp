#include<iostream>
using namespace std;

const int N = 4;

int maze[N][N] =
{
{1, 0, 0, 0},
{1, 1, 0, 1},
{0, 1, 0, 0},
{1, 1, 1, 1}
};

int path[N][N] = {0};
int visited[N][N] = {0};

void printPath()
{
    cout << "Path:\n\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= N)
    return false;

    if(maze[row][col] == 0)
    return false;

    if(visited[row][col] == 1)
    return false;

    return true;
}

bool solveMaze(int row, int col){
    if (row == N - 1 && col == N - 1){
        path[row][col] = 1;
        return true;
    }

    if(!isSafe(row, col))
    return false;

    path[row][col] = 1;
    visited[row][col] = 1;

    // go right
    if(solveMaze(row, col + 1))
    return true;

    // go down
    if(solveMaze(row + 1, col))
    return true;

    // backtrack
    path[row][col] = 0;

    return false;

}

int main()
{
    cout << "Maze:\n\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    if (solveMaze(0, 0)){
        cout << "Path found!\n\n";
        printPath();
    }
    else{
        cout << "No path exists.\n";
    }
    
    return 0;
}