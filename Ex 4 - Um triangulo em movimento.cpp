#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 800;

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
*	Exercício 4
*	Fazer um triângulo se mover da esquerda
*	para a direita
*/
	if(x2 >= 4.65)
		s = -1.0f;
	if(x2 <= -4.65)
		s = 1.0f;

	x2 = x2+v*s;
	glColor3f(0.5f, 0.0f, 0.5f);

	glBegin(GL_TRIANGLES);
		glVertex3f(x2, 0.0f, 0.0f);
		glVertex3f(x2+2.0f, 3.0f, 0.0f);
		glVertex3f(x2-2.0f, 3.0f, 0.0f);
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