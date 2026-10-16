
#include <iostream>
using namespace std;

int color[4] = {0, 0, 0, 0};

//this function is checking whether a color can be assigned to a department
bool isSafe(int dept, int c) {
    if (dept == 0) {  // A
        if (color[1] == c || color[2] == c)
            return false;
    }

    else if (dept == 1) {  // B
        if (color[0] == c || color[2] == c ||
            color[3] == c)
            return false;
    }

    else if (dept == 2) {  // C
        if (color[0] == c || color[1] == c ||
            color[3] == c)
            return false;
    }

    else if (dept == 3) {  // D
        if (color[1] == c || color[2] == c)
            return false;
    }

    return true;
}

bool assignColors(int dept) {
    // all four departments have been colored
    if (dept == 4)
        return true;

    // try colors Red, Green, and Blue
    for (int c = 1; c <= 3; c++) {
        if (isSafe(dept, c)) {
            color[dept] = c;

            if (assignColors(dept + 1))
                return true;

            // backtrack
            color[dept] = 0;
        }
    }

    return false;
}

int main() {
    if (assignColors(0)) {
        cout << "Valid coloring:\n";

        for (int i = 0; i < 4; i++) {
            cout << char('A' + i) << " = ";

            if (color[i] == 1)
                cout << "Red";
            else if (color[i] == 2)
                cout << "Green";
            else if (color[i] == 3)
                cout << "Blue";

            cout << endl;
        }
    }
    else {
        cout << "No valid coloring exists.";
    }

    return 0;
}
