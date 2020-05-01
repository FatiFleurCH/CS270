#include <iostream>
using namespace std;
// The function is returning a pointer
int *dynamicArray(int size);
void displayArray(const int[], int);
int main(){

	int length = 0;
	int *dynamic_array = nullptr;
	cout << "Enter the length to allocate for the array: ";
	cin >> length;
	dynamic_array = dynamicArray(length);
	displayArray(dynamic_array, length);
	return 0;
}

int *dynamicArray(int size){
	// Assign a null value to the array pointer
	int *pArray = nullptr;

	// check if the size if correct
	if (size <= 0){
		return nullptr;
	}
	// Dynamically allocate memory for an array
	pArray = new int[size];

	// Seeding the random number generator
	srand((unsigned int) time(NULL));

	for(int i = 0; i < size; i++){
		pArray[i] = rand();
	}
	return pArray;
}
void displayArray(const int dynamic_array[], int size){
    for(int i = 0; i < size; i++){
		cout << dynamic_array[i] << endl;
	}
}
