
#include <iostream>
using namespace std;

int arr[] = {2, 3, 5, 6, 8};
int subset[5];
int n = 5;

bool generateSubsets(int index, int size)
{
    if (index == n)
    {
        int sum = 0;
        for (int i = 0; i < size; i++){
            sum += subset[i];
        }
        if (sum == 9){
            cout << "Subset found: ";

            for (int i = 0; i < size; i++)
            {
                cout << subset[i] << " ";
            }

            cout << endl;
            return true;
        }

        return false;
    }

    subset[size] = arr[index];

    if (generateSubsets(index + 1, size + 1))
        return true;

    if (generateSubsets(index + 1, size))
        return true;

    return false;
}

int main()
{
    if (!generateSubsets(0, 0))
    {
        cout << "No subset found whose sum is 9." << endl;
    }

    return 0;
}
