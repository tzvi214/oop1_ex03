#pragma once
#include "ImageDataStructure.h"
#include "Pixel.h"
#include <iosfwd>
#include <iostream>
using std::cout;
using std::endl;

class Image
{
public:
	Image(); //  c-tor 1
	Image(int, int); // c-tor 2
	Image(int, int, Pixel); // c-tor 3

private:
	ImageDataStructure m_Image;
};