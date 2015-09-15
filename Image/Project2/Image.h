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
	void setPixel(int argb, int x, int y) {
		pixels[x + y*width] = argb;
	}
	int getPixel(int x, int y) {
		return pixels[x + y*width];
	}
	void setARGB(int x, int y, int argb) {
		pixels[x + y * width] = argb;
	}
	int getARGB(int x, int y) {
		return pixels[x + y * width];
	}
	int getWidth() { return width; }
	int getHeight() { return height; }

	int* getPixels() {
		return pixels;
	}
//	void setPixels(int* pixels) { //verificar 
//		for (int i = 0; i < height; i++) {
//			for (int j = 0; i < width; i++) {
//				pixels[i]->setRGB()
//			}
//		}
//	}
	void dropPixels(){//da uma zerada nos pixels
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					setPixel(0, i, j);
				}
			}
	}
	void plot(int* foreground, int xi, int yi, int largura, int altura) {
		for (int i = 0; i < largura; i++) {
			for (int j = 0; j < altura; j++) {
				int a = (foreground[j] >> 24) & 0xff;
				if (a == 0) {
					continue;
				}
				else if (a = 255) {
					setARGB(i, j, foreground[j]);
				}
				else {
					int r = (foreground[i] >> 16) & 0xff;
					int g = (foreground[i] >> 8) & 0xff;
					int b = (foreground[i]) & 0xff;

					int aThis = (getARGB(i, j) >> 24) & 0xff;
					int rThis = (getARGB(i, j) >> 16) & 0xff;
					int gThis = (getARGB(i, j) >> 8) & 0xff;
					int bThis = (getARGB(i, j)) & 0xff;

					int calcr = (rThis*(1-a)+r*a);
					int calcg = (gThis*(1 - a) + r*a);
					int calcb = (bThis*(1 - a) + r*a);
					int argb = (255 << 24) | (calcr << 16) | (calcg << 8) | (calcb);
					setARGB(i, j, argb);
				}
			}
		}
	}

private:
	int *pixels; // alternativamente char *pixels – 1 byte por canal
				 // neste caso, pixels = new char[w*h*3];
	int width, height;
};

#endif
