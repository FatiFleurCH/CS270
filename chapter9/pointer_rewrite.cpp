#include <iostream>
using namespace std;
void getValues(int*, int*);
int doSomething(int*, int*);
int main(){
	int varX = 0,
		varY = 0,
		result = 0;
	int *x = nullptr;
	int *y = nullptr;
	x = &varX;
	y = &varY;
	// Magically changes x and y haha
	getValues(x, y);
	result = doSomething(x, y);
	cout << "\tThe result is: " << result;
	
	return 0;
}
void getValues(int *x, int *y){
	cout << "\tEnter two numbers: ";
	cin >> *x >> *y;
}
int doSomething(int* x, int* y){
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return (*x + *y);
}