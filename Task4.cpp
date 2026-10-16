#include<iostream>
using namespace std;

int doubleAmount(int n){
	if(n < 2){
		return 10;
	}
	
	return 2 * doubleAmount(n-1);
}

int main(){
	int n;
	cout << "Enter no. of days: ";
	cin >> n;
	
	cout << "Day " << n << " amount: Rs. " <<  doubleAmount(n);
    
	return 0;
}