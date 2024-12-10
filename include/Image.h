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
	Image& operator=(const Image&) = default;
	bool operator==(const Image&)const;
	Image operator+(const Image& other) const;
	Image operator|(const Image&) const;
	
	Image operator&(const Image&) const;
	
	void operator~();

	Pixel& operator()(unsigned int, unsigned int);
	const Pixel& operator()(unsigned int, unsigned int) const;

	int GetHeight() const { return m_Image.GetHeight() ; }
	int GetWidth() const { return m_Image.GetWidth() ; }

	friend std::ostream& operator<<(std::ostream&, const Image&);
private:
	ImageDataStructure m_Image;

};

Image& operator|=( Image&, const Image&);
Image operator*(const Image& image, unsigned int n);
Image operator*(unsigned int n, const Image& image) ;
Image& operator*=( Image& image, unsigned int n);
bool operator!=(const Image&, const Image);
Image& operator+= (Image&, const Image&);
Image& operator&=(Image&, const Image&);
