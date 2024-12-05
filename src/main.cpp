#include <iostream> 
#include "Pixel.h"
#include "Image.h"
#include "ImageDataStructure.h"

using std::cout;
using std::endl;


int main()
{
	//Pixel p1(219);
	//Pixel p2;
	//cout << endl << "p1 is: " << p1;
	//cout << endl << "p2 is: " << p2;

	// p1 &= p2;
	//cout << endl << "p1 is: " << p1;
	//cout << endl << "p2 is: " << p2;
	Image image1;
	Image image2(20, 10);
	Image image3(20, 10, 219);
	//cout << image;
	return 0;
}