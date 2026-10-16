
#include<iostream>
using namespace std;

char arr[] = {'A', 'B', 'C', 'D'};
int n = 4;

void permute(int index)
{
    if(index == n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    for(int i = index; i < n; i++)
    {
        swap(arr[index], arr[i]);

        permute(index + 1);
        
        swap(arr[index], arr[i]);
    }
}

int main()
{
    permute(0);
    return 0;
}
