#include "Pixel.h"
#include <iostream>

Pixel::Pixel(unsigned char pixel) : m_color(pixel) {}

unsigned char Pixel::getColor() const
{
	return m_color;
}

bool Pixel::operator==(const Pixel& other) const
{
	return (m_color == other.m_color);
}

bool Pixel::operator!=(const Pixel& other) const
{
	return !(*this == other);
}

Pixel Pixel::operator|(const Pixel& other) const
{
	return (Pixel  (m_color >= other.m_color ? m_color : other.m_color));
}

void Pixel::operator|=(const Pixel& other)
{
	*this = *this | other;
}

Pixel Pixel::operator&(const Pixel& other) const
{
	return	(Pixel (m_color <= other.m_color ? m_color : other.m_color));
	
}

void Pixel::operator&=(const Pixel& other)
{
	*this = *this & other;
}

void Pixel::operator=(const Pixel& other)
{
	m_color = other.m_color;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel)
{
	return os << pixel.getColor(); 	 // return ostream
}