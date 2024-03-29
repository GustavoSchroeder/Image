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
	void dropPixels() {//da uma zerada nos pixels
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setPixel(0, i, j);
			}
		}
	}
	void plot(Image *foreground, int xi, int yi) { //verificar com o professor
		for (int i = 0; i < foreground->getWidth() * foreground->getHeight(); i++) {
			int x = i % foreground->getWidth();
			int y = i / foreground->getWidth();
			int argb = foreground->getPixel(x, y);
			x =+ xi;
			y = +yi;

			int a = (argb >> 24) & 0xff;

			if (a == 0) {
				continue;
			} 
			else if (a == 255) {
				this->setPixel(argb, x, y);
			}
			else {
				int r = ((foreground->getPixel(x, y))>> 16) & 0xff;
				int g = ((foreground->getPixel(x, y)) >> 8) & 0xff;
				int b = (foreground->getPixel(x, y)) & 0xff;

				int aThis = ((this->getPixel(x, y)) >> 24) & 0xff;
				int rThis = ((this->getPixel(x, y)) >> 16) & 0xff;
				int gThis = ((this->getPixel(x, y)) >> 8) & 0xff;
				int bThis = (this->getPixel(x, y)) & 0xff;

				int calcr = (rThis*(1 - a) + r*a);
				int calcg = (gThis*(1 - a) + r*a);
				int calcb = (bThis*(1 - a) + r*a);
				int argb = (255 << 24) | (calcr << 16) | (calcg << 8) | (calcb);
				foreground->setPixel(x, y, argb); //verificar com o professor
			}
		}
	}
	void plotInt(int* foreground, int xi, int yi, int largura, int altura) {
		for (int i = 0; i < largura * altura; i++) {
			int x = i % largura;
			int y = i / largura;
			x = +xi;
			y = +yi;
			int a = (foreground[i] >> 24) & 0xff;
			if (a == 0) {
				continue;
				
			}
			else if (a = 255) {
				setPixel(foreground[i], x, y);
			}
			else {
				int r = (foreground[i] >> 16) & 0xff;
				int g = (foreground[i] >> 8) & 0xff;
				int b = (foreground[i]) & 0xff;
				
				int aThis = (getPixel(x, y) >> 24) & 0xff;
				int rThis = (getPixel(x, y) >> 16) & 0xff;
				int gThis = (getPixel(x, y) >> 8) & 0xff;
				int bThis = (getPixel(x, y)) & 0xff;
					
				int calcr = (rThis*(1 - a) + r*a);
				int calcg = (gThis*(1 - a) + r*a);
				int calcb = (bThis*(1 - a) + r*a);
				int argb = (255 << 24) | (calcr << 16) | (calcg << 8) | (calcb);
				setPixel(argb, x, y);
					
			}
		}
		
		void cutPlot(int * foreground, int x, int y, int w, int h, int posX, int PosY) {
			double fx, fy, a, r, g, b, fr, fg, fb, rr, gg, bb;

			for (int i = 0; i < h*w; i++) {
				fy = posY + y + i / w;
				fx = posX + x + i % w;

				a = (unsigned(foreground[i] >> 24)) & 0xff;
				a = a / 255;
				fr = (unsigned(foreground[i] >> 16)) & 0xff;
				fg = (unsigned(foreground[i] >> 8)) & 0xff;
				fb = (unsigned(foreground[i])) & 0xff;
		
				r = (getPixel(fx, fy) >> 16) & 0xff;
				g = (getPixel(fx, fy) >> 8) & 0xff;
				b = getPixel(fx, fy) & 0xff;

				rr = r * (1 - a) + fr * a;
				gg = g * (1 - a) + fg * a;
				bb = b * (1 - a) + fb * a;

				if (rr != 255){
					int teste = 0;
				}

				//setPixel();
				setPixel((getPixel(fx, fy) >> 24 & 0xff), rr, gg, bb, fx + fy*width);
			}
	}

private:
	int *pixels; // alternativamente char *pixels – 1 byte por canal
				 // neste caso, pixels = new char[w*h*3];
	int width, height;
};

#endif
