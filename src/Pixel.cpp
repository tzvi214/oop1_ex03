#include "Pixel.h"
#include <iostream>

Pixel::Pixel(unsigned char pixel) : m_color(pixel) {}

unsigned char Pixel::getColor() const
{
	return m_color;
}

bool Pixel::operator==(const Pixel& other) const
{
	return (this->m_color == other.m_color);
}

bool Pixel::operator!=(const Pixel& other) const
{
	return !(*this == other);
}

unsigned char Pixel::operator|(const Pixel& other) const
{
	return (this->m_color >= other.m_color) ? m_color : other.m_color;
}

void Pixel::operator|=(const Pixel& other)
{
	*this = *this | other;
}

unsigned char Pixel::operator&(const Pixel& other) const
{
	return(this->m_color <= other.m_color ? m_color : other.m_color);
}

void Pixel::operator&=(const Pixel& other)
{
	*this = *this & other;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel)
{
	os << pixel.getColor();
	return os; // return ostream
}