#pragma once

#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

class Image {
public:
	Image(int w, int h) {
		width = w; height = h;
		pixels = new int[w*h];
	}
	~Image(void) {
		delete[] pixels;
	}
	void setPixel(int rgb, int x, int y) {
		pixels[x + y*width] = rgb;
	}
	int getPixel(int x, int y) {
		return pixels[x + y*width];
	}
	void setRGB(int x, int y, int rgb) {
		pixels[x + y * width] = rgb;
	}
	int getRGB(int x, int y) {
		return pixels[x + y * width];
	}
	int getWidth() { return width; }
	int getHeight() { return height; }

	int* getPixels() {
		return pixels;
	}

	//void setPixel(int w, int h) {
	//	pixels
	//}
private:
	int *pixels; // alternativamente char *pixels – 1 byte por canal
				 // neste caso, pixels = new char[w*h*3];
	int width, height;
};

#endif