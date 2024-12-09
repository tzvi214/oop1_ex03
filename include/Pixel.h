#pragma once
#include <iosfwd>


class Pixel
{
public:
	Pixel(unsigned char pixel = ' ');
	unsigned char getColor() const;
	bool operator==(const Pixel&)const;
	bool operator!=(const Pixel&)const;
	Pixel operator|(const Pixel&)const;
	void operator|=(const Pixel&);
	Pixel operator&(const Pixel&)const;
	void operator&=(const Pixel&);
	void operator=(const Pixel&);

private:
	unsigned char m_color;
};

std::ostream& operator<< (std::ostream&, const Pixel&); // Global Function.
