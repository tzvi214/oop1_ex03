#include "Image.h"

Image::Image() :m_Image() {}

Image::Image(int height, int width) :m_Image(height, width) {}

Image::Image(int height, int width, Pixel pixel) :m_Image(height, width, pixel) {}
