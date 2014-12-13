
#include "Image.h"
#include "Graphics.h"
#include <vector>

#pragma once

namespace GameLibrary
{
	class TextureImage
	{
		friend class Graphics;
	private:
		void*texture;
		std::vector<bool> pixels;
		unsigned int width;
		unsigned int height;

		TextureImage(const TextureImage&);
		TextureImage& operator=(const TextureImage&);

	public:
		TextureImage();
		~TextureImage();
		
		void create(unsigned int width, unsigned int height, Graphics&graphics);
		void update(const Color*pixels);
		//void update(const Color*pixels, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		
		bool loadFromFile(const String&path, Graphics&graphics, String&error = String());
		bool loadFromImage(const Image&image, Graphics&graphics, String&error = String());
		//Image copyToImage() const;
		
		bool checkPixel(unsigned int index) const;
		bool checkPixel(unsigned int x, unsigned int y) const;
	};
}