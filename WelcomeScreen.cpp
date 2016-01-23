#include<glut.h>
//#include<stdlib.h>

float win1,win2;
bool* keystates=new bool[256];
float angle=0.0;
float angle1=0.0;

void LineLoop(float x,float y)
{
	glColor3f(0.6,0.4,0.4);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x,y);
	glVertex2f(x+1,y);
	glVertex2f(x+1,y+1);
	glVertex2f(x,y+1);
	glEnd();
}
void square(float x,float y,int size)
{
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
	glVertex2f(x+size,y);
	glVertex2f(x+size,y+size);
	glVertex2f(x,y+size);
	glEnd();
}
void drawstring(float x,float y,char *string)
{
	int i;
	glRasterPos2f(x,y);
	for(i=0;string[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}
void cube()
{
	glColor3f(1,1,0.5);
	glutWireTeapot(3);
}
void display()
{
	int width=glutGet(GLUT_WINDOW_WIDTH);
	int height=glutGet(GLUT_WINDOW_HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8,1,0);
	square(-9.5,-9.5,19);
	glColor3f(0,1,0);
	square(-7,-6,13);
	glColor3f(1,0,0);
	drawstring(-7,4,"DR.AMBEDKAR INSTITUTE OF TECHNOLOGY"); 
	drawstring(-3,3,"Welcome");
	cube();
	glutSwapBuffers();
}
void idle()
{
}

void keyboard1(unsigned char keys,int x,int y)
{
	keystates[keys]=true;
	if(keys=='c')
		glutHideWindow();
	glClearColor(0,0,0,1);
	glutPostRedisplay();
}

void keyboard2(unsigned char keys,int x,int y)
{
	int i=0;
	keystates[keys]=true;
	glutPostRedisplay();
}

void Sphere_rotate()
{
	glRotatef(angle,1,0,0);
	glRotatef(angle,0,1,0);
	glRotatef(angle,0,0,1);
	//gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Need to Clarify this function use
	glColor4f(0.7,0.2,0.5,0.4);
	glutWireTorus(3,0,100,100);
	glutPostRedisplay();
}

void Torus_rotate()
{
	glScalef(1,0.5,2);// Created an Ellipse
	glRotatef(angle1,1,0,0);
	glRotatef(angle1,0,1,0);
	glRotatef(angle1,0,0,1);
	glColor3f(1,1,0);
	glutWireTorus(5,0,1,20);
	glutPostRedisplay();
}

void display2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(0.8,0.7,0.6,1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	Sphere_rotate();
	Torus_rotate();
	glutSwapBuffers();
	angle+=0.05;
	angle1+=0.05;
}

void mouse(int button,int state,int x,int y)
{
	// float i;
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,0,1);
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
	glClearColor(0.6,1,1,1);
	LineLoop(x,y);
	}
	glutPostRedisplay();	

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
	//gluPerspective(100, (float)w / (float)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char ** argv)
{
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInit(&argc,argv);
	glutInitWindowPosition(500,0);
	win2=glutCreateWindow("2nd Window");
	glutDisplayFunc(display2);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard2);
	glutReshapeFunc(reshape);
	glutInitWindowPosition(0,10);
	win1=glutCreateWindow("Welcome Screen");
	glutSetWindow(win1);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard1);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();
} 