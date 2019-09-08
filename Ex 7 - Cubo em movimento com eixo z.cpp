#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 800;

float x2 = 1.5f;
float s = 1.0f;
float v = 0.1f;

void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, -10.0f);

/*
*	Exercício 2,5
*	Mover o cubo da direita para a esquerda e vice-versa
*	com eixo Z
*/
	// Lembre-se: considerar a linha da direita
	if(x2 >= 6.65)
		s = -1.0f;
	if(x2 <= -3.65)
		s = 1.0f;

	x2 = x2+v*s;

	glColor3f(0.5f, 0.2f, 0.5f);

	glBegin(GL_LINES);
		// Linha frente - Direita
		glVertex3f(x2, 1.5f, 0.0f);
		glVertex3f(x2, -1.5f, 0.0f);

		// Linha frente - Esquerda
		glVertex3f(x2-3.0f, 1.5f, 0.0f);
		glVertex3f(x2-3.0f, -1.5f, 0.0f);

		// Linha frente - Baixo
		glVertex3f(x2, -1.5f, 0.0f);
		glVertex3f(x2-3.0f, -1.5f, 0.0f);

		// Linha frente - Cima
		glVertex3f(x2, 1.5f, 0.0f);
		glVertex3f(x2-3.0f, 1.5f, 0.0f);

		// Linha trás - Direita
		glVertex3f(x2, 1.5f, -3.0f);
		glVertex3f(x2, -1.5f, -3.0f);

		// Linha trás - Esquerda
		glVertex3f(x2-3.0f, 1.5f, -3.0f);
		glVertex3f(x2-3.0f, -1.5f, -3.0f);

		// Linha trás - Baixo
		glVertex3f(x2, -1.5f, -3.0f);
		glVertex3f(x2-3.0f, -1.5f, -3.0f);

		// Linha trás - Cima
		glVertex3f(x2, 1.5f, -3.0f);
		glVertex3f(x2-3.0f, 1.5f, -3.0f);

		// Ligando - Cima Direita
		glVertex3f(x2, 1.5f, 0.0f);
		glVertex3f(x2, 1.5f, -3.0f);

		// Ligando - Cima Esquerda
		glVertex3f(x2-3.0f, 1.5f, 0.0f);
		glVertex3f(x2-3.0f, 1.5f, -3.0f);

		// Ligando - Baixo Direita
		glVertex3f(x2, -1.5f, 0.0f);
		glVertex3f(x2, -1.5f, -3.0f);

		// Ligando - Baixo Esquerda
		glVertex3f(x2-3.0f, -1.5f, 0.0f);
		glVertex3f(x2-3.0f, -1.5f, -3.0f);
	glEnd();

	
	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}
}

void initView()
{
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	initView();

	glutMainLoop();
	return 0;
}