#include <iostream>
#include <cmath>
using namespace std;
int main()

{
	cout << "Enter the angle theta in degrees: " << endl;
	double theta;
	cin >> theta;
	theta = (M_PI/180)*theta;
	int asterisk = 0;

	for (int line = 0; line < 30; line++) //counts lines 
	{
		if (line*tan(theta) >= 20 && line*tan(theta) <= 30)
		{
		for (asterisk = 0; asterisk <= 20; asterisk++)
			{
				cout << "*";
			}
		}
		else
		{
			for (asterisk = 0; asterisk <= line*tan(theta); asterisk++) //counts characters per line
			{				
				cout << "*";
			}
		}
	cout << endl;
	}
	return 0;
}