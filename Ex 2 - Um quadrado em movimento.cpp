#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 800;

float x1 = -6.65f;
float x2 = 6.65f;
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
*	Exercício 2
*	Fazer um quadrado se movimentar na tela
*	da direita para esquerda e voltar
*/
	if(x1 >= 3.65)
		s = -1.0f;
	if(x1 <= -6.65)
		s = 1.0f;

	x1 = x1+v*s;

	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_LINES);
		//Esquerda
		glVertex3f(x1, -1.5f, 0.0f);
		glVertex3f(x1, 1.5f, 0.0f);

		//Direita
		glVertex3f(x1+2.75f, -1.5f, 0.0f);
		glVertex3f(x1+2.75f, 1.5f, 0.0f);

		//Cima
		glVertex3f(x1, 1.5f, 0.0f);
		glVertex3f(x1+2.75f, 1.5f, 0.0f);

		//Baixo
		glVertex3f(x1, -1.5f, 0.0f);
		glVertex3f(x1+2.75f, -1.5f, 0.0f);
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
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	glutMainLoop();
	return 0;
}