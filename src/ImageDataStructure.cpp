#include "ImageDataStructure.h"
#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure(int height, int width, Pixel pixel) :m_height(height), m_width(width)
{
	
	m_Image = new Pixel * [m_height];
	for (int i = 0; i < m_height; i++)
	{
		m_Image[i] = new Pixel[m_width];
	}

	
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_Image[i][j] = pixel;
		}
	}
}

ImageDataStructure::~ImageDataStructure()
{
	for (int i = 0; i < m_height; i++)
	{
		delete [] m_Image[i];
	}
	delete m_Image;

}

bool ImageDataStructure::operator==(const ImageDataStructure& other) const
{
	if (!this->m_Image || !other.m_Image)
		return false;

	if (this->m_height != other.m_height || this->m_width != other.m_width)
		return false;

	for(int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
		{
			if (m_Image[row][col] != other.m_Image[row][col])
				return false;
		}

	return true;
}

bool ImageDataStructure::operator!=(const ImageDataStructure& other) const
{
	return !(this->m_Image == other);
}
