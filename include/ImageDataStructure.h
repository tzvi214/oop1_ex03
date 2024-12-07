#pragma once
#include <iostream>
#include "Pixel.h"

using std::cout;
using std::endl;


class ImageDataStructure
{
public:
	ImageDataStructure(int height = 0, int width = 0, Pixel pixel = ' ');
	ImageDataStructure(const ImageDataStructure&); // copy c-tor
	ImageDataStructure(int, int, Pixel**& pixel);
	~ImageDataStructure();
	int GetHeight()const;
	int GetWidth()const;
	bool operator==(const ImageDataStructure&)const;
	bool operator!=(const ImageDataStructure&)const;
	void operator=(const ImageDataStructure&);
	ImageDataStructure operator+(const ImageDataStructure& other) const;
	friend std::ostream& operator<<(std::ostream&, const ImageDataStructure&);

private:
	Pixel** m_ImageDS = nullptr;
	int m_width;
	int m_height;
	void copy(const ImageDataStructure&);
	Pixel** allocImage(int, int) const;
	void deleteImage();
};
