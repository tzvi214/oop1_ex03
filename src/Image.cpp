#include "Image.h"

Image::Image() :m_Image() {}

Image::Image(int height, int width) :m_Image(height, width) {}

Image::Image(int height, int width, Pixel pixel) :m_Image(height, width, pixel) {}

Image::Image(const Image& other) :m_Image(other.m_Image) {}

bool Image::operator==(const Image& other) const
{
	return (m_Image == other.m_Image);
}

bool  Image::operator!=(const Image& other)const
{
	return !(*this == other);
}

void Image::operator=(const Image& other)
{
	this->m_Image = other.m_Image;
}

std::ostream& operator<<(std::ostream& os, const Image& image)
{

	return os << image.m_Image;
}

Image operator*(unsigned int n, const Image& image)
{
	return image*n;
}

Image Image::operator+(const Image& other) const
{
	Image temp;

	temp.m_Image = m_Image + other.m_Image;
	return temp;
}

void Image::operator+=(const Image& other)
{
	*this = *this + other;
}

Image Image::operator*(unsigned int n) const
{
	if(n ==0)
	return Image();
	Image temp(m_Image.GetHeight(), m_Image.GetWidth() * n); // יצירת תמונה בגודל מתאים		
	for (int i = 0; i < n; i++)
		temp += *this;
		
	return temp;
}

void Image::operator*=(unsigned int n)
{
	if (n == 0)
	{
		*this = Image();
		return;
	}
	*this = n * *this;
}
