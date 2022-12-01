#include <gl/glew.h>  // A cross-platform open-source C/C++ extension loading library
#include <gl/freeglut.h>   // Handle the window-managing operations
#include <iostream>
#include<math.h>
using namespace std;
float theta, theta2;
double pi = 22.0 / 7.0, Angle = 0;
char face_change = 'h'; //h=>Happy s=>Sad r=>Surprise


void happy_mouth()
{
	glLineWidth(10); //set the width of line
	glTranslated(15, -20, 0); // move to 15 in X aixs and -20 in Y aixs 
	glRotatef(230, 0, 0, 1); //rotate the object by 230 degree around the center point of x and y
	glBegin(GL_LINE_STRIP); //draw line 
	for (float i = 0; i <= pi * 0.5; i += pi / 500)
		glVertex2f(sin(i) * 30, -20 + cos(i) * 30);
	glEnd();
}
void sad_mouth()
{
	glLineWidth(10); //set the width of line
	glTranslated(0, -55, 0); // move to 0 in X aixs and -55 in Y aixs 
	glRotatef(45, 0, 0, 1); //rotate the object by 45 degree around the center point of x and y
	glBegin(GL_LINE_STRIP);
	for (float i = 0; i <= pi * 0.5; i += pi / 500)
		glVertex2f(sin(i) * 30, cos(i) * 30);
	glEnd();
}
void surprise_mouth()
{
	glLineWidth(10);
	glTranslated(0, -30, 0);
	glRotatef(230, 0, 0, 1);
	glBegin(GL_LINE_STRIP);
	for (float i = 0; i <= pi * 0.5; i += pi / 500)
		glVertex2f(sin(i) * 5, cos(i) * 5);
	glEnd();
}

void happy_eyes()
{

	//right eye
	glColor3f(1.0, 1.0, 1.0); //set the color of the eye to white
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(15 + sin(i) * 3, 10 + cos(i) * 3);
	glEnd();

	glColor3f(0.0, 0.0, 0.0); //set the color of the ball of the eye to black
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(14 + sin(i) * 2, 10 + cos(i) * 2);
	glEnd();

	//left eyes
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(-15 + sin(i) * 3, 10 + cos(i) * 3);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(-14 + sin(i) * 2, 10 + cos(i) * 2);
	glEnd();

}
void surprise_eyes()
{
	//right eye
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(15 + sin(i) * 5, 10 + cos(i) * 5);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(14 + sin(i) * 2, 11 + cos(i) * 2);
	glEnd();

	//left eyes

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(-15 + sin(i) * 5, 10 + cos(i) * 5);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(-14 + sin(i) * 2, 11 + cos(i) * 2);
	glEnd();

}
void sad_eyes()
{

	//right eyes
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(15 + sin(i) * 3, 10 + cos(i) * 3);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(15 + sin(i) * 2, 9 + cos(i) * 2);
	glEnd();

	//sad eyes
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(-15 + sin(i) * 3, 10 + cos(i) * 3);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.5)
		glVertex2f(-15 + sin(i) * 2, 9 + cos(i) * 2);
	glEnd();

}

void face(double red, double green, double blue)
{

	glColor3f(red, green, blue); // RGB GET FROM THE FACE FUNCTUIN WHEN CALL
	if (red == 0 && green == 0, blue == 0) //IF THE VALUE OF THE COLOR IS BLACK THEN DRAW FACE WITH LINE ==> HAPPAY FACE
		glBegin(GL_LINE_STRIP);
	else //ELSE DRAW FACE WITH POLYGON ==> sad and surprise FACE
		glBegin(GL_POLYGON);

	for (float i = 0; i <= 5000; i += 0.7)
		glVertex2f(cos(i) * 50, sin(i) * 50);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	//draw  right ear
	glPushMatrix(); //to clear the buffer for transformation
	{
		glTranslated(42, 35, 0);
		glRotatef(77, 0, 0, 1);
		glBegin(GL_POLYGON);

		for (float i = 0; i <= pi * 1.3; i += pi / 500)
			glVertex2f(sin(i + 0.2) * 20, cos(i) * 18);

		glEnd();
	}
	glPopMatrix();

	// draw left ear
	glPushMatrix();
	{
		glTranslated(-42, 35, 0);
		glScaled(1, -1, -1);
		glRotatef(-103, 0, 0, 1);
		glBegin(GL_POLYGON);

		for (float i = 0; i <= pi * 1.3; i += pi / 500)
			glVertex2f(sin(i + 0.2) * 20, cos(i) * 18);

		glEnd();
	}
	glPopMatrix();

	//draw eyes
	glPushMatrix();
	{
		glTranslated(17, 10, 0);
		glRotatef(70, 0, 0, 1);
		glBegin(GL_POLYGON);

		for (float i = 0; i <= 5000; i += 0.5)
			glVertex2f(sin(i + 0.3) * 15, cos(i) * 15);

		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslated(-17, 10, 0);
		glRotatef(15, 0, 0, 1);
		glBegin(GL_POLYGON);

		for (float i = 0; i <= 5000; i += 0.5)
			glVertex2f(sin(i + 0.3) * 15, cos(i) * 15);

		glEnd();
	}
	glPopMatrix();




	glBegin(GL_POLYGON);
	for (float i = 0; i <= 5000; i += 0.8)
		glVertex2f(sin(i) * 7, -10 + cos(i) * 4);
	glEnd();

	glFlush();
}
void display()
{

	glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
	glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
	glLoadIdentity();                // Reset the model-view matrix
	gluLookAt(0, 0, 60, 0, 0, 0, 0, 1, 1);

	switch (face_change)
	{
	case 'h':
	{
		glPushMatrix();
		glRotated(Angle, 0, 1, 0);
		face(0.00, 0.00, 0.00);
		happy_eyes();
		happy_mouth();
		glPopMatrix();
		break;
	}
	case 's':
	{
		glPushMatrix();
		glRotated(Angle, 1, 0, 0);
		face(0.93, 0.93, 0.93);
		sad_eyes();
		sad_mouth();
		glPopMatrix();
		break;
	}
	case 'r':
	{
		glPushMatrix();
		glRotated(Angle, 0, 0, 1);
		face(0.87, 0.87, 0.73);
		surprise_eyes();
		surprise_mouth();
		glPopMatrix();
		break;
	}
	default:
		break;
	}

	glFlush();
}

void MyInit(void)
{
	glClearColor(0.80, 0.67, 0.43, 0.0); //to set the background color
	glMatrixMode(GL_PROJECTION); //The projection transformation defines the viewing volume 
	glLoadIdentity(); //The glLoadIdentity function replaces the current matrix with the identity matrix
	glOrtho(-120, 120, -100, 100, 0, 120); //The gluOrtho function sets up a 3-dimensional orthographic viewing region.
	//glOrtho(left, right, bottom, top,znear,zfar)

	cout << "******the happy face rotate around the y-axis," << endl
		<< "*******then change to sad face with different color and also rotate around the x - axis," << endl
		<< "********finally change to surprise face with different color and also make it rotate around the z - axis." << endl;

	cout << "- Use letter 'H' to rotate the simile face counterclockwise relative to y-axis/n" << endl
		<< "- Use letter 'h' to rotate the simile face clockwise relative to y - axis/n" << endl
		<< "- Use letter 'S' to rotate the sad face counterclockwise relative to x - axis" << endl
		<< "- Use letter 's' to rotate the sad face clockwise relative to x - axis" << endl
		<< "- Use letter 'R' to rotate the surprise face counterclockwise relative to z - axis" << endl
		<< "- Use letter 'r' to rotate the surprise face clockwise relative to z - axis" << endl;

	cout << " *********** Faces Rotate 360  degree then Change To Another Face ************\n";
	cout << " ***************    Each Face Rotate With Its Letter Look Abov  ************" << endl;
}

void windowKey(unsigned char key, int x, int y)
{
	//letter "H" to rotate the simile face counterclockwise relative to y-axis
	if (key == 'H' && face_change == 'h')
	{
		Angle = Angle + 10;
		if (Angle >= 360)
		{
			Angle = 0;
			face_change = 's';  //change to sad face
		}
		glutPostRedisplay();
	}
	//letter "h" to rotate the simile face clockwise relative to y - axis
	if (key == 'h' && face_change == 'h')
	{
		Angle = Angle - 10;
		if (Angle <= -360)
		{
			Angle = 0;
			face_change = 's';  //change to sad face
		}
		glutPostRedisplay();
	}
	if (key == 'S' && face_change == 's')             // letter "S" to rotate the sad face counterclockwise relative to x - axis
	{
		Angle = Angle + 10;
		if (Angle >= 360)
		{
			Angle = 0;
			face_change = 'r';  //change to surprise face
		}
		glutPostRedisplay();
	}
	if (key == 's' && face_change == 's')             //letter "s" to rotate the sad face clockwise relative to x-axis
	{
		Angle = Angle - 10;
		if (Angle <= -360)
		{
			Angle = 0;
			face_change = 'r';  //change to *_* surprise face
		}
		glutPostRedisplay();
	}
	if (key == 'R' && face_change == 'r')            //letter "R" to rotate the surprise face counterclockwise relative to z-axis
	{
		Angle = Angle + 10;
		if (Angle >= 360)
		{
			Angle = 0;
			face_change = 'h';  //change to happy face
		}
		glutPostRedisplay();
	}
	if (key == 'r' && face_change == 'r')            //letter "r" to rotate the surprise face clockwise relative to z-axis  
	{
		Angle = Angle - 10;
		if (Angle <= -360)
		{
			Angle = 0;
			face_change = 'h';  //change to happy *_* face whitch is the first face
		}
		glutPostRedisplay();
	}

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(1000, 700); //set the initial window size to 1000 pixel width and 700 pixel hight.
	glutCreateWindow("Assigment1");// Set the title of the window.
	MyInit();
	glutKeyboardFunc(windowKey);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}



























