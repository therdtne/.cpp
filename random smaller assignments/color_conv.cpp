#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // Enter your code here
   
   double red, green, blue;
   cin >> red >> green >> blue;
   double white = max(max(red/255,green/255), blue/255); 
   double cyan = (white-red/255)/white;
   double magenta = (white-green/255)/white;
   double yellow = (white-blue/255)/white;
   double black = 1-white;

   cout << "cyan: " << cyan << endl; 
   cout << "magenta: " << magenta << endl; 
   cout << "yellow: " << yellow << endl;
   cout << "black: " << black << endl << endl;  
   
   
   
   return 0;
}
