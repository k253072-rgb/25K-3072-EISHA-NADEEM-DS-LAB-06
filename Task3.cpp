#include<iostream>
using namespace std;

int sumInt(int digit){
	
	if(digit == 0){
		return 0;
	}
	
	int last = digit % 10;
	
	return last + sumInt(digit/10); 
}

int main(){
	int n = 345;
	
	cout << "Amount: " << n << endl;
	cout << "Sum of digits: " << sumInt(n) << endl;
	
	return 0;
}