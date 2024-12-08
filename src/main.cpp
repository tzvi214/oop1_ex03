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
	Image image1(3,2, GRAY);
	Image image2(2, 3, BLACK);
	
	cout << "image1" << endl << image1 << endl;
	
	cout << "image2" << endl << image2 << endl;
	
	Image image3 = image1 | image2;
	cout << "image3" << endl << image3 << endl;// זה עובד לי
	image1 |= image2;

	cout << "image1" << endl << image1 << endl;// זה עובד לי

	cout << image1 | image2 ;// זה לא עובד לי
	return EXIT_SUCCESS;
}