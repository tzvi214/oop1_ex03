#pragma once
#include <iostream>
#include "Pixel.h"

using std::cout;
using std::endl;
class ImageDataStructure
{
public:
	ImageDataStructure(int height = 0, int width = 0, Pixel pixel = ' ');
	ImageDataStructure(int , int , Pixel** &pixel);
	ImageDataStructure(const ImageDataStructure&); // copy c-tor
	~ImageDataStructure();
	bool operator==(const ImageDataStructure &other)const;
	bool operator!=(const ImageDataStructure& other)const;
	void operator+=(const ImageDataStructure &other) ;
	ImageDataStructure operator+(const ImageDataStructure& other) const;
	friend std::ostream& operator<<(std::ostream&, const ImageDataStructure&);
	void operator=(const ImageDataStructure&);
	ImageDataStructure operator|(const ImageDataStructure& other)const;

private:
	
	int m_width;
	int m_height;
	Pixel** m_ImageDS;
	Pixel** buildMatrix(int row, int col)const;
	void copy(const ImageDataStructure&);
	


};
