#include<iostream>
using namespace std;

void printAscending(int n){
    if(n == 0){
        return;
    }

    printAscending(n-1);
	cout << n << endl;
}

int main(){
    int n = 5;

    printAscending(n);
    
    return 0;
}