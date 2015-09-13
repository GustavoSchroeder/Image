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
	void setPixels(int* pixelsSet, int rgb) { //verificar 
		int size = sizeof(pixelsSet);
		for (int i = 0; i < size; i++) {
			pixelsSet[i];
		}
	}
	void dropPixels(){//da uma zerada nos pixels
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					setPixel(0, i, j);
				}
			}
	}
	void plot(int* foreground, int xi, int yi, int largura, int altura) {
		for (int i = 0; i<largura; i++) {
			for (int j = 0; j<altura; j++) {
				//calcular x e y
				//pixels [xx+yy*largura] = foreground [x+y*largura];
			}
		}
	}

private:
	int *pixels; // alternativamente char *pixels – 1 byte por canal
				 // neste caso, pixels = new char[w*h*3];
	int width, height;
};

#endif
