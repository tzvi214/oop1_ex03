#include "ImageDataStructure.h"
const unsigned char BLACK = (unsigned char)219;
const unsigned char WHITE = (unsigned char)32;


ImageDataStructure::ImageDataStructure(int height, int width, Pixel pixel)
	:m_height(height), m_width(width)
{
	// Dynamic allocation of a two-dimensional array
	m_ImageDS = allocImage(m_height, m_width);

	// Initializing the pixels
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_ImageDS[i][j] = pixel;
		}
	}
}

ImageDataStructure::ImageDataStructure(const ImageDataStructure& other) // coyp c-tor
	: m_height(other.m_height), m_width(other.m_width)
{
	m_ImageDS = allocImage(m_height, m_width);
	this->copy(other);
}

ImageDataStructure::ImageDataStructure(int height, int width, Pixel**& pixel)
	: m_height{ height }, m_width{ width }, m_ImageDS{ pixel }
{
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

Pixel** ImageDataStructure::allocImage(int height, int width)const
{

	Pixel** image = new Pixel * [height];
	for (int i = 0; i < height; i++)
	{
		image[i] = new Pixel[width];
	}

	return image;
}

void ImageDataStructure::deleteImage()
{
	if (m_ImageDS)
	{
		for (int i = 0; i < m_height; i++)
		{
			delete[] m_ImageDS[i];
		}
		if (m_width)
			delete[] m_ImageDS;
		m_ImageDS = nullptr;
	}
}

ImageDataStructure::~ImageDataStructure()
{
	this->deleteImage();
}


bool ImageDataStructure::operator==(const ImageDataStructure& other) const
{
	// Quick check for self-comparison
	if (this == &other)
		return true;

	if (!this->m_ImageDS || !other.m_ImageDS) // type: Pixel**
		return false;

	if (this->m_height != other.m_height || this->m_width != other.m_width) // type: int
		return false;

	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
		{
			if (m_ImageDS[row][col] != other.m_ImageDS[row][col]) // type: Pixel
				return false;
		}
	return true;
}

bool ImageDataStructure::operator!=(const ImageDataStructure& other) const
{
	return !(*this == other);
}

void ImageDataStructure::operator=(const ImageDataStructure& other)
{
	this->deleteImage();
	this->m_ImageDS = allocImage(other.m_height, other.m_width);// the members height, width update in "copy" function.
	this->copy(other);
}

ImageDataStructure ImageDataStructure::operator+(const ImageDataStructure& other) const
{
	int newRow = (m_height > other.m_height) ? m_height : other.m_height;// max();
	int newCol = m_width + other.m_width;
	Pixel** newMatrix = allocImage(newRow, newCol);

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

ImageDataStructure ImageDataStructure::operator|(const ImageDataStructure& other) const
{
	// i need to check if is nullptr
	int newRow = (m_height > other.m_height)? m_height : other.m_height;
	int newCol = (m_width > other.m_width) ? m_width : other.m_width;
	Pixel** newMatrix = allocImage(newRow, newCol);

	for (int i = 0; i < newRow; i++)
	{

		for (int j = 0; j < newCol; j++)
		{
			if (i < m_height && j < m_width)// בתווך של this
			{
				if (i < other.m_height && j < other.m_width)// in this and in other
				{
					newMatrix[i][j] = m_ImageDS[i][j] | other.m_ImageDS[i][j];
				}
				else// only in this
					newMatrix[i][j] = m_ImageDS[i][j];
			}

			else if (i < other.m_height && j < other.m_width)// only in other
			{
				newMatrix[i][j] = other.m_ImageDS[i][j];
			}
			else// nat in this and nat in other
				newMatrix[i][j] = Pixel();
		}
	}
	return ImageDataStructure(newRow, newCol, newMatrix);
}

ImageDataStructure ImageDataStructure::operator&(const ImageDataStructure& other) const
{
	// i need to check if is nullptr
	int newRow = (m_height < other.m_height) ? m_height : other.m_height;
	int newCol = (m_width < other.m_width) ? m_width : other.m_width;
	Pixel** newMatrix = allocImage(newRow, newCol);

	//i dont need to check the size of both matrix
	for(int i =0; i < newRow; i++)
		for (int j = 0; j < newCol; j++)
		{
			newMatrix[i][j] = m_ImageDS[i][j] & other.m_ImageDS[i][j];
		}

	return ImageDataStructure(newRow, newCol, newMatrix);
}

void ImageDataStructure::operator~()
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (m_ImageDS[i][j] == BLACK)
				m_ImageDS[i][j] = WHITE;
			else if (m_ImageDS[i][j] == WHITE)
				m_ImageDS[i][j] = BLACK;
		}
	}
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
Pixel& ImageDataStructure::operator()(unsigned int height, unsigned int width)
{
	if (!m_ImageDS)
		throw std::runtime_error("Image data structure is not initialized");

	if (height >= (unsigned int)m_height || width >= (unsigned int)m_width)
		throw std::out_of_range("Pixel index out of range");

	return m_ImageDS[height][width];
}

const Pixel& ImageDataStructure::operator()(unsigned int height, unsigned int width) const
{
	return const_cast<ImageDataStructure*>(this)->operator()(height, width);

}

