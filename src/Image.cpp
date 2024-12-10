#include "Image.h"

Image::Image() :m_Image() {}

Image::Image(int height, int width) :m_Image(height, width) {}

Image::Image(int height, int width, Pixel pixel) :m_Image(height, width, pixel) {}

Image::Image(const Image& other) :m_Image(other.m_Image) {}

Image::Image(const ImageDataStructure& imageDS) :m_Image{ imageDS } {}
	
//---------------- OPERTORS -------------------
bool Image::operator==(const Image& other) const
{
	return (m_Image == other.m_Image);
}

std::ostream& operator<<(std::ostream& os, const Image& image)
{
	return os << image.m_Image;
}

Image Image::operator+(const Image& other) const
{
	return Image(m_Image + other.m_Image);
}

Image Image::operator|(const Image& other) const
{
	 return Image(m_Image | other.m_Image);
}

Image Image::operator&(const Image& other) const
{
	return Image(m_Image & other.m_Image);
}

void Image::operator~()
{
	~m_Image;
}

Pixel& Image::operator()(unsigned int height, unsigned int width)
{
	return m_Image(height, width);
}

const Pixel& Image::operator()(unsigned int height, unsigned int width) const
{
	return m_Image(height, width);
}

//----------------GLOBAL FONCTION------------------
Image& operator|=( Image& first, const Image& second)
{
	return first = first | second;
}

Image operator*(const Image& image, unsigned int n)
{
	if (n == 0)
		return Image();
	Image temp(image.GetHeight(), image.GetWidth() * n); // יצירת תמונה בגודל מתאים		
	for (unsigned i = 0; i < n; i++)
		temp += image;

	return temp;
}

Image operator*(unsigned int n, const Image& image)
{
	return image * n;
}

Image& operator*=(Image& image, unsigned int n)
{
	return (image = image *n);
}

bool operator!=(const Image& first, const Image second)
{
	return !(first == second);
}

Image& operator+=(Image& first, const Image& second)
{
	
	return (first = first + second);
}

Image& operator&=(Image& first, const Image& second)
{
	return (first = first & second);
}
