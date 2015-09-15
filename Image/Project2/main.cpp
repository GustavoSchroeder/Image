#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <math.h>
#include "Image.h"

using namespace std;
Image *imagem = NULL;
int winWidth = 400;
int winHeight = 400;

void leitura() {
	//faz algoritmo
}

void ChangeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) {
		h = 1;
	}

	winWidth = w;
	winHeight = h;

	glViewport(0, 0, w, h);

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the clipping volume
	gluOrtho2D(0.0f, (GLfloat)w, 0.0, (GLfloat)h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void init(void) {
	glClearColor(0.00, 0.00, 0.00, 0.00);

	// Targa's are 1 byte aligned
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	imagem = new Image(400, 400);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < imagem->getHeight(); i++) {
		for (int j = 0; j < imagem->getWidth(); j++) {
			int r = rand() % 256;
			int g = rand() % 256;
			int b = rand() % 256;
			int rgb = (r << 16) | (g << 8) | b; //move os bytes
			imagem->setARGB(i, j, rgb);
		}
	}
}

void RenderScene(void) {
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);
	// Use Window coordinates to set raster position
	glRasterPos2i(0, winHeight - imagem->getHeight());
	// Draw the pixmap
	if (imagem != NULL) {
		glDrawPixels(imagem->getWidth(), imagem->getHeight(), GL_RGBA, GL_UNSIGNED_BYTE, imagem->getPixels());
	}
	glutSwapBuffers();
}

	int main(int argc, char** argv) {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GL_DOUBLE);
		glutInitWindowSize(400, 400);
		glutCreateWindow("Desenho de Imagem - Processamento Grafico");

		// especifica qual a função que trata da alteração da janela
		glutReshapeFunc(ChangeSize);

		// especifica qual é a função de renderização da tela
		glutDisplayFunc(RenderScene);
		init();

		// inicia looping do OpenGL
		glutMainLoop();

		// limpa memória ao final do looping
//		finish();

		return 0;
}
