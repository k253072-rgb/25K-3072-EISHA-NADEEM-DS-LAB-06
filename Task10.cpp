#include <iostream>
#include <string>
using namespace std;

const int R = 3, C = 4;

char grid[R][C] = {
    {'C', 'A', 'X', 'X'},
    {'X', 'T', 'X', 'X'},
    {'X', 'X', 'X', 'X'}
};

bool visited[R][C] = {false};
string word = "CAT";

bool searchWord(int row, int col, int index){

    if(index == word.length())
        return true;

    if (row < 0 || row >= R || col < 0 || col >= C)
        return false;

    if(visited[row][col] || grid[row][col] != word[index])
        return false;

    visited[row][col] = true;

    if(searchWord(row - 1, col, index + 1) || searchWord(row + 1, col, index + 1) ||
        searchWord(row, col - 1, index + 1) || searchWord(row, col + 1, index + 1))
        return true;

        //backtrack
    visited[row][col] = false;

    return false;
}

int main() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (searchWord(i, j, 0)) {
                cout << "Word CAT exists!";
                return 0;
            }
        }
    }

    cout << "Word CAT does not exist!";
    return 0;
}