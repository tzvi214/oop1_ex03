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

			else if (other.m_height > i)

				//else if (i < other.m_height )
				newMatrix[i][j] = other.m_ImageDS[i][j - m_width];
			else
				newMatrix[i][j] = Pixel();
		}
	}
	return ImageDataStructure(newRow, newCol, newMatrix);
}

//ImageDataStructure ImageDataStructure::operator+(const ImageDataStructure& other) const
//{
//	// גובה ורוחב של התמונה החדשה
//	int newRow = std::max(m_height, other.m_height); // גובה מקסימלי
//	int newCol = m_width + other.m_width;           // רוחב משולב
//
//	// יצירת מטריצה חדשה
//	Pixel** newMatrix = buildMatrix(newRow, newCol);
//
//	// מילוי מטריצת התוצאה
// for (int i = 0; i < newRow; i++) 
//	 for (int j = 0; j < newCol; j++)
//	 {
//		 if (i < m_height && j < m_width)
//			 // העתקת התמונה הראשונה (A)
//			 newMatrix[i][j] = m_ImageDS[i][j];
//		 else if (i < other.m_height && j >= m_width)
//			 // העתקת התמונה השנייה (B) למקום החדש
//			 newMatrix[i][j] = other.m_ImageDS[i][j - m_width];
//		 else
//			 // מילוי "רקע" בצבע לבן
//			 newMatrix[i][j] = Pixel(); // הנח ש-W מייצג פיקסל לבן
//	 }
//	return ImageDataStructure(newRow, newCol, newMatrix);
//}


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
