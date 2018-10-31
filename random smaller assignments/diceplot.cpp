#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


void printHistogram(int counts[]) 
{
	for (int i = 0; i < 21; i++)
	{
		cout << setw(2) << i+4 << ": ";
		for (int x = 0; x < counts[i]; x++)
		{
			cout << "X";
		}
		cout << endl;
	}

}

int roll()
{
	return rand() % 6+1; 
}

int main()
{
	int n; 
	int counts[21];

	cout << "How many rolls would you like? " << endl;
	cin >> n;
	for (int i = 0; i < 21; i++)
	{
		counts[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
		sum = sum + roll();

		}
		counts[sum-4]++;	
	}
	printHistogram(counts);





	return 0;
}
