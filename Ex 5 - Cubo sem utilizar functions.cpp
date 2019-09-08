#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 800;

void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, -10.0f);
/*
*	Exercício 1
*	Desenhar um cubo usando vértices e linhas
*	apenas. Não usar funções do GLUT, como glutWireCube()
*/
	glColor3f(0.5f, 0.0f, 0.5f);
	glBegin(GL_LINES);
		// Linha 1 - Direita
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 3.0f, 0.0f);

		// Linha 1 - Esquerda
		glVertex3f(-3.0f, 0.0f, 0.0f);
		glVertex3f(-3.0f, 3.0f, 0.0f);

		// Linha 1 - Baixo
		glVertex3f(-3.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);

		// Linha 1 - Cima
		glVertex3f(-3.0f, 3.0f, 0.0f);
		glVertex3f(0.0f, 3.0f, 0.0f);

		// Linha 2 - Direita Cima
		glVertex3f(0.0f, 3.0f, 0.0f);
		glVertex3f(2.0f, 4.0f, 0.0f);

		// Linha 2 - Esquerda Cima
		glVertex3f(-3.0f, 3.0f, 0.0f);
		glVertex3f(-1.0f, 4.0f, 0.0f);

		// Linha 2 - Cima
		glVertex3f(2.0f, 4.0f, 0.0f);
		glVertex3f(-1.0f, 4.0f, 0.0f);

		// Linha 2 - Direita Trás
		glVertex3f(2.0f, 4.0f, 0.0f);
		glVertex3f(2.0f, 1.0f, 0.0f);

		// Linha 2 - Baixo Trás
		glVertex3f(2.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);

		// Linha 2 - Esquerda Trás
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 4.0f, 0.0f);

		// Linha 2 - Baixo Esquerda
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-3.0f, 0.0f, 0.0f);

		// Linha 2 - Baixo Direita
		glVertex3f(2.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
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

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
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
	glutCreateWindow("Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	glutMainLoop();
	return 0;
}