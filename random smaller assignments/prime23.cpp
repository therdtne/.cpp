#include <iostream>
using namespace std;

int main()
{
	cout << "Enter a positive integer: " << endl; 
	int n;
	cin >> n;

int threes = 0;
int twos = 0;

while (n%3 == 0 && n/3 <= 3)
{
	n = n/3;
	threes++;
}
while (n%2 == 0 && n/3 <= 3)
{
	n = n/2;
	twos++;
}
if (threes == 0 && twos == 0)
{
	cout << "No" << endl;
}
else 
{
	cout << "Yes" << endl;
	cout << "Twos= " << twos << " " << "Threes= " << threes << endl;
}
return 0;
}
