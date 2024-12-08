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
	Image(); // (default) c-tor 1
	Image(int, int); // c-tor 2
	Image(int, int, Pixel); // c-tor 3
	Image(const Image&); // copy c-tor
	Image(const ImageDataStructure& imageDS);
	bool operator==(const Image&)const;
	bool operator!=(const Image&)const;
	void operator=(const Image&);
	Image operator+(const Image& other) const;
	void operator += (const Image & other);
	friend std::ostream& operator<<(std::ostream&, const Image&);
	Image operator*(unsigned int n)const;
	friend Image operator*(unsigned int n, const Image& image) ;
	void operator *=(unsigned int n);
	Image operator|(const Image&) const;
	void operator|=(const Image&);
private:
	ImageDataStructure m_Image;

};
