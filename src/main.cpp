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
	Image image1{5,2, BLACK};
	Image image2{ 5,2, GRAY };
	Image image3{ 35,2, GRAY };

	 cout << (image1 = image2 = image3);
	
	return EXIT_SUCCESS;
}