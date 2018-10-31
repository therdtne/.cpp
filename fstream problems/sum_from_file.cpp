#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile("num2.txt");
  int num;
  ifile >> num;
  int sum = 0;
  for (int i = 0; i < num; i++)
  {
  	int t;
  	ifile >> t;
  	sum += t;
  }



  cout << "Sum=" << sum << endl;

  return 0;
}
