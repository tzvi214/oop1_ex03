#include <iostream> 
#include "Pixel.h"
#include "Image.h"
#include "ImageDataStructure.h"
const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;

using std::cout;
using std::endl;


int main()
{
	ImageDataStructure im1(55,5, GRAY);
	ImageDataStructure im2(5, 5, BLACK);
	
	cout << im2+im1;
	//cout << "\n \n \n \n \n ";
	cout << im1 + im2;
	//im1 += im2;
//	cout << im1;
	//cout << im2;
	return 0;
}