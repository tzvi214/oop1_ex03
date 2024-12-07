#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure(int height, int width, Pixel pixel) 
	:m_height(height), m_width(width)
{
	
	m_ImageDS = buildMatrix(m_height, m_width);
	
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_ImageDS[i][j] = pixel;
		}
	}
}

ImageDataStructure::ImageDataStructure(int height, int width,  Pixel**& pixel)
	: m_height{ height }, m_width{ width }, m_ImageDS{ pixel }
{ }

ImageDataStructure::~ImageDataStructure()
{
	if (m_ImageDS)
	{
		for (int i = 0; i < m_height; i++)
		{
			delete[] m_ImageDS[i];
		}
		delete[] m_ImageDS;
		m_ImageDS = nullptr;
	}
}

ImageDataStructure::ImageDataStructure(const ImageDataStructure& other) // copy c-tor
	: m_height(other.m_height), m_width(other.m_width)
{
	m_ImageDS = buildMatrix(m_height, m_width);
	this->copy(other);
}

bool ImageDataStructure::operator==(const ImageDataStructure& other) const
{
	/*if (this == &other)
		return true;*/

	if (!this->m_ImageDS || !other.m_ImageDS)
		return false;

	if (this->m_height != other.m_height || this->m_width != other.m_width)
		return false;

	for(int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
		{
			if (m_ImageDS[row][col] != other.m_ImageDS[row][col])
				return false;
		}

	return true;
}

bool ImageDataStructure::operator!=(const ImageDataStructure& other) const
{
	return !(*this == other);
}

void ImageDataStructure::operator+=(const ImageDataStructure& other) 
{
	*this = *this + other;
}

ImageDataStructure ImageDataStructure::operator+(const ImageDataStructure& other) const
{
	int newRow = (m_height > other.m_height)? m_height : other.m_height;// max();
	int newCol = m_width + other.m_width;
	Pixel** newMatrix = buildMatrix(newRow, newCol);

	for (int i = 0; i < newRow; i++)
	{
		
		for (int j = 0; j < newCol; j++)
		{
			if (m_width > j && m_height > i)
				newMatrix[i][j] = m_ImageDS[i][j];

			 else if (j >= m_width && j - m_width < other.m_width && i < other.m_height)
				newMatrix[i][j] = other.m_ImageDS[i][j - m_width];
			else
				newMatrix[i][j] = Pixel();
		}
	}
	return ImageDataStructure(newRow, newCol, newMatrix);
}


Pixel** ImageDataStructure::buildMatrix(int row, int col)const
{
	Pixel** Matrix = new Pixel * [row];
	for (int i = 0; i < row; i++)
	{
		Matrix[i] = new Pixel[col];
	}

	return Matrix;
}

std::ostream& operator<<(std::ostream& os, const ImageDataStructure& image)
{
	if (!image.m_ImageDS)
		return os;

	for (int i = 0; i < image.m_height; i++)
	{
		for (int j = 0; j < image.m_width; j++)
		{
			os << image.m_ImageDS[i][j];

		}
		os << endl;
	}

	return os;
}
void ImageDataStructure::copy(const ImageDataStructure& other)
{
	m_height = other.m_height;
	m_width = other.m_width;

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_ImageDS[i][j] = other.m_ImageDS[i][j];
		}
	}
}

void ImageDataStructure::operator=(const ImageDataStructure& other)
{
	this->copy(other);
}

