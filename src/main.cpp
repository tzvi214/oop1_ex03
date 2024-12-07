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
	ImageDataStructure im1(3,2, GRAY);
	ImageDataStructure im2(2, 3, BLACK);
	
	cout << im2+im1;
	
	im1 = im2;
	/*cout << im1 + im2;*/
	cout << "\n \n \n";
	//cout << im2;
	return 0;
}