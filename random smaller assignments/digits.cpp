#include <iostream>

using namespace std;
int main()
{
	cout << "Enter an integer between 0 and 999: " << endl;
	int n;
	cin >> n;
	int x,y,z;

	x = (n)/100; //100's place
	y = (n%100)/10; //10's place 
	z = (n%10); //1's place

	cout << "1's digit is: " << z << endl;
	cout << "10's digit is: " << y << endl;
	cout << "100's digit is: " << x << endl;

	return 0;
}