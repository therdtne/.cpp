#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int main(int argc, char *argv[])
{
  if(argc < 3){
    cout << "Please enter the name of the file to read as an argument and the integer to search for" << endl;
    return 1;
  }

  // Declare the ifstream variable here an open the file
  // specified as the 1st command line argument


  // Read the number of integers specified on the first line
  // into the following variable
  int numInts;

  
  // Dynamically allocate an array of ints of size: numInts
  //  using the 'new' operator


  // Read the integers on the 2nd line of text in the file into
  //  the array you allocated


  // Convert the 2nd command line argument to an integer named searchval


  // Average the last half of the array
  int occurrences = 0;


  cout << searchval << " appears " << occurrences << " times." << endl;

  // Use delete to deallocate the array you new'ed



  return 0;
}
