#include <iostream>
#include <map>
using namespace std;
void getValues(int*, const int);
int calcMean(int*, const int);

int main(){
	int *array = nullptr;
	int size = 0;
	cout << "\tHow long is the array: ";
	cin >> size;
	array = new int[size];
	getValues(array, size);
	cout << "The mean is: " << calcMean(array, size);
	return 0;
}
void getValues(int* array, const int size)
{
	for(int index = 0; index < size; index++)
	{
		cout << "\tEnter value#" << index + 1 << ": ";
		cin >> *(array + index);
	}
	cout << "\n";
}
int calcMean(int* array, const int size)
{
	map<int, int> numRepetition;
	for(int i = 0; i < size; i++)
	{
		if(numRepetition[*(array + i)] >= 1)
		{
			numRepetition[*(array + i)] += 1;
		}
		else
		{
			numRepetition[*(array + i)] = 1;
		}
		
	}
	int mean = 0;
	for(int index = 0; index < size; index ++)
	{
		if(numRepetition[*(array + index)] > mean){
			mean = *(array + index) ;
		}
	}
	return mean;
}