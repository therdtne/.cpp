#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) 
{
   for (int i=left; i < width+left; i++) 
   {
      for (int j=top; j < height+top; j++)
      {
        if (i==left || i==width+left-1 || j==top || j==top+height-1) // makes sure it is borders being drawn
         {
            // if (i<0 || i>255 || j<0 || j>255)
            // {
            //    image[i][j] = 255;
            // }
            if (i>=0 && i<SIZE && j>=0 && j<SIZE)
            {
               image[i][j] = 0;
            }
         }
      }
   }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) 
{ 
   
   for (double theta = 0.0; theta < 2*M_PI; theta += .01)
   {
      int x = (width/2)*cos(theta)+cx;
      int y = (height/2)*sin(theta)+cy;
      if (x>=0 && x<SIZE && y>=0 && y<SIZE)
      {
         image[x][y] = 0;
      }     
   } 
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
   int input;
   int top;
   int left;
   int height;
   int width;
   int cx;
   int cy;
   do
   { 
      cout << "To draw a rectangle, enter 0." << endl;
      cout << "To draw an ellipse, enter 1." << endl;
      cout << "To save your drawing as 'output.bmp' and quit, enter 2." << endl;
      cin >> input;
      if (input == 0)
      {
         cout << "top: " << endl << "left: " << endl << "height: " << endl << "width: " << endl;
         cin >> top >> left >> height >> width;
         draw_rectangle(top, left, height, width); 
      }
      else if (input == 1)
      {
         cout << "cy: " << endl << "cx: " << endl << "height: " << endl << "width: " << endl;
         cin >> cy >> cx >> height >> width;
         draw_ellipse(cy, cx, height, width);
      }
   } while (input != 2);
   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
