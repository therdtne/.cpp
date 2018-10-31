#include <iostream>
#include <cstring>
 
using namespace std;

int main()
{
	char mystring[80] = "ComputerScience";
	char yourstring[80];
	char* astring = 0;

	yourstring = mystring; // does this make a copy? 
							// does not make a copy, will not compile.
	strncpy(astring, mystring, 80); // does this make a copy?

	astring = mystring; // is this legal assignment?
	strncpy(yourstring, mystring, 80); // make a copy? study for midterm
	cout << astring << endl;
	cout << yourstring << endl;

	mystring[0] = '*'; // which one actually made a copy?
	cout << astring << endl;
	cout << yourstring << endl;

	return 0;
}