#include <iostream>

using namespace std;
void getTestScores(double*, const int);
void sortScores(double*, const int);
double calcAverage(double*, const int);
void displayResults(double*, const int, double);
int main(){
	/* Dynamically allocated array */
   double *testScores = nullptr;
   int numScores = 0;
   double averageScore = 0.0;
   /* Get the number of scores */
    cout << "\n\tHow many test-scores do you wish to enter? ";
    cin >> numScores;
    cout << "\n";
    /* Dynamically allocates the array to hold the number of
       test scores the user wishes to enter */
    testScores = new double[numScores];
    getTestScores(testScores, numScores);
    sortScores(testScores, numScores);
    averageScore = calcAverage(testScores, numScores);
    displayResults(testScores, numScores, averageScore);
    /* Free up memory */
    delete[] testScores;
}
void getTestScores(double *testScores, const int numScores){
	for(int i = 0; i < numScores; i++){
		cout << "\t Score #" << i + 1 << ": ";
		cin >> *(testScores + i);
		while(*(testScores + i) < 0){
			cout << "Please enter a positive value!" <<endl;
			cout << "Enter score for test #" <<i + 1<< endl;
			cin >> *(testScores + i);
		}
	}
	cout << "\n";
}

void sortScores(double *testScores, const int numScores)
{
   int start = 0,
       minIndex = 0,
       index = 0;

   double minElem = 0.0;

   for (start = 0; start < (numScores - 1); start++)
   {
      minIndex = start;
      minElem =  *(testScores + start);

      for (index = start + 1; index < numScores; index++)
      {
         if (*(testScores + index) < minElem)
         {
            minElem = *(testScores + index);
            minIndex = index;
         }
      }

    	*(testScores + minIndex) = *(testScores + start);
      	*(testScores + start) = minElem;
   }
}
double calcAverage(double *testScores, const int numScores){
	double total = 0.0,
			average = 0.0;
	for(int index = 0; index < numScores; index ++){
		total += *(testScores + index);
	}
	average = total / numScores;
	return average;
}
void displayResults(double *testScores, const int numScores, double averageScore)
{
	cout << "\n\n\tTEST SCORES ORDERED\n";
	for(int index = 0; index < numScores; index ++)
	{
		cout << "\tScore #" << index + 1 << ": " << *(testScores + index) << endl;

	}
	cout << "\tThe average of scores: " << averageScore << endl;
}
