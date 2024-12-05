#pragma once
#include "Pixel.h"

class ImageDataStructure
{
public:
	ImageDataStructure(int height = 0, int width = 0, Pixel pixel = ' ');
	~ImageDataStructure();
	bool operator==(const ImageDataStructure &other)const;
	bool operator!=(const ImageDataStructure& other)const;
	//ImageDataStructure operator+=
private:
	
	int m_width;
	int m_height;
	Pixel** m_Image;
};