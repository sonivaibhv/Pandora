#include<glut.h>

float win1,win2,angle=0;
int x,y;

void DrawSquare(int x,int y)
{
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(x,y);
		glVertex2f(x+5,y);
		glVertex2f(x+5,y+5);
		glVertex2f(x,y+5);
	glEnd();
}

void mouse(int button,int state,int x1,int y1)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		x=x1;
		y=y1;
		DrawSquare(x1,y1);
	}
	else
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		glClearColor(1,0,0,1);
		DrawSquare(x1,y1);
	}
	glutPostRedisplay();
}
void keyboard1(unsigned char keys,int x,int y)
{
	if(keys=='c')
	glClearColor(0,1,0,1);
	glutPostRedisplay();
}

void RotateCube()
{
	glRotatef(angle,1,0,0);
	glutWireSphere(5,50,5);
	glutPostRedisplay();
}

void display2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.4,0.6,0.7);
	glRotatef(angle,1,0,0);
	glutSolidCube(5);
	glutSwapBuffers();
	glFlush();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.4,0.6,0.7);
	RotateCube();
	glutSwapBuffers();
	angle+=0.05;
	glFlush();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	glOrtho(-10,10,-10*(float)h/(float)w,10*(float)h/(float)w,-10,10);
	else
	glOrtho(-10*(float)h/(float)w,10*(float)h/(float)w,-10,10,-10,10);
	gluPerspective(60, (float)w / (float)h, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
}

int main()
{
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowPosition(510,10);
	win2=glutCreateWindow("Hand");
	init();
	glutDisplayFunc(display2);
	glutReshapeFunc(reshape);
	glutInitWindowPosition(0,0);
	win1=glutCreateWindow("Droid Screen");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard1);
	glutMainLoop();
}