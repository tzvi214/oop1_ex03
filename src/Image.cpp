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
