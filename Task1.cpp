#include<iostream>
#include<string.h>
using namespace std;

void printReverseString(string word, int n){

    if(n==0){
        cout << word[n];
        return;
    }

    cout << word[n];
    printReverseString(word, n-1);
}

int main(){
    string word = "eisha";

    printReverseString(word, word.length());

    return 0;
}