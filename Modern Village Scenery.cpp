#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>
using namespace std;


bool rainday = false;
float _rain = 0.0;
//train
bool t_forward = false;
bool t_backword = false;
bool t_stop = false;
float trainWheelAngle1 = 0.0f;
float trainSpeed = 0.0f;

//car1
bool c1_forward= false;
bool c1_backward= false;
bool c1_stop= false;
float c1_WheelAngle1 = 0.0f;
float position_car1=0;

//car2
bool c2_forward= false;
bool c2_backward= false;
bool c2_stop= false;
float c2_WheelAngle1 = 0.0f;
float position_car2=0;

//boat1
float position_boat1=0;
//boat2
float position_boat2=0;
bool b_forward = false;
bool b_backward = false;

//cloud
float cloud1_position=0.0;
float cloud2_position=0.0;
float cloud3_position=0.0;

float sun_position=-700.0f;

void Rain(int value){

if(rainday){

    _rain += 5.0f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand();
        int y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}

void SquareShape(float a, float b, float c, float d, float p, float q, float x, float y)
{
glBegin(GL_QUADS);
glVertex2f(a,b);
glVertex2f(c,d);
glVertex2f(p,q);
glVertex2f(x,y);
glEnd();
}

void Moon()
{
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=30;
		float x = 200+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
}

void NightSky()
{
    glColor3ub(0, 12, 51);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,830.0);
    glVertex2f(1000.0,830.0);
    glVertex2f(1000.0,1000.0);
    glVertex2f(0.0,1000.0);
    glEnd();

    ///tree1
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();

    ///tree2
    glPushMatrix();
    glTranslatef(70.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();

    ///tree3
    glPushMatrix();
    glTranslatef(370.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();

    ///tree4
    glPushMatrix();
    glTranslatef(470.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();

    ///tree5
    glPushMatrix();
    glTranslatef(700.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();

    ///tree6
    glPushMatrix();
    glTranslatef(790.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();
    ///done

    ///star
    glPointSize(3);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex2f(150.0,950.0);
    glEnd();

    glPointSize(3);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex2f(120.0,950.0);
    glEnd();

    glPointSize(3);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex2f(190.0,990.0);
    glEnd();

    glPointSize(3);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex2f(390.0,975.0);
    glEnd();

    glPointSize(3);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex2f(590.0,960.0);
    glEnd();

    glPointSize(3);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex2f(790.0,940.0);
    glEnd();

    glPointSize(3);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex2f(890.0,900.0);
    glEnd();

    glPointSize(3);
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex2f(40.0,910.0);
    glEnd();
    ///star done

}
void UpdateSun(int value)
{
    sun_position += 0.07;
    if(sun_position > 0.0)
    {
        sun_position = 0.0f;
    }
	glutPostRedisplay();

	glutTimerFunc(100, UpdateSun, 0);
}
void Sun()
{
    glPushMatrix();
    glTranslatef(0.0,sun_position,0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 92, 51);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 620+r * cos(A);
		float y = 930+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glutTimerFunc(20, UpdateSun, 0);
}
void Cloud2()
{
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(cloud2_position,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 450+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 440+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 490+r * cos(A);
		float y = 950+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 510+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 450+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x-125,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 440+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x-125,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 490+r * cos(A);
		float y = 950+r * sin(A);
		glVertex2f(x-125,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 510+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x-125,y );
	}
	glEnd();
	glPopMatrix();
}

void NightCloud2()
{
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(cloud2_position,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 450+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 440+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 490+r * cos(A);
		float y = 950+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 510+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 450+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x-125,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 440+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x-125,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 490+r * cos(A);
		float y = 950+r * sin(A);
		glVertex2f(x-125,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 510+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x-125,y );
	}
	glEnd();
	glPopMatrix();
}

void Cloud3()
{
   glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(cloud3_position,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 450+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x+400,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 440+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x+400,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 490+r * cos(A);
		float y = 950+r * sin(A);
		glVertex2f(x+400,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 510+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x+400,y );
	}
	glEnd();
	glPopMatrix();
}

void NightCloud3()
{
   glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(cloud3_position,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 450+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x+400,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 440+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x+400,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 490+r * cos(A);
		float y = 950+r * sin(A);
		glVertex2f(x+400,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 510+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x+400,y );
	}
	glEnd();
	glPopMatrix();
}


void Sky()
{
    glColor3ub(77, 166, 255);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,830.0);
    glVertex2f(1000.0,830.0);
    glVertex2f(1000.0,1000.0);
    glVertex2f(0.0,1000.0);
    glEnd();


}
void Tree3()
{
    ///tree3
    glPushMatrix();
    glTranslatef(370.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();
}
void Tree4()
{
    ///tree4
    glPushMatrix();
    glTranslatef(470.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();
}
void TreeWithHill()
{
    ///tree1
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();

    ///tree2
    glPushMatrix();
    glTranslatef(70.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();


   Tree3();
   Tree4();


    ///tree5
    glPushMatrix();
    glTranslatef(700.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();

    ///tree6
    glPushMatrix();
    glTranslatef(790.0,0.0,0.0);
    glColor3ub(38, 26, 13);
    glBegin(GL_LINES);
    glVertex2f(200.0,830.0);
    glVertex2f(200.0,845.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,855.0);
    glVertex2f(220.0,855.0);
    glVertex2f(200.0,875.0);
    glEnd();

    glColor3ub(0, 179, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0,840.0);
    glVertex2f(220.0,840.0);
    glVertex2f(200.0,855.0);
    glEnd();
    glPopMatrix();
    ///done
}
void Cloud1()
{
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(cloud1_position,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 450+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x-350,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<350;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 440+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x-350,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 490+r * cos(A);
		float y = 950+r * sin(A);
		glVertex2f(x-350,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 510+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x-350,y );
	}
	glEnd();

	glPopMatrix();
}

void NightCloud1()
{
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(cloud1_position,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 450+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x-350,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<350;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 440+r * cos(A);
		float y = 940+r * sin(A);
		glVertex2f(x-350,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 490+r * cos(A);
		float y = 950+r * sin(A);
		glVertex2f(x-350,y );
	}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = 510+r * cos(A);
		float y = 900+r * sin(A);
		glVertex2f(x-350,y );
	}
	glEnd();

	glPopMatrix();
}
void RiverAndRoadsideArea()
{
    //glColor3ub(139,115,89);
    glColor3ub(238,232,170);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,170.0);
    glVertex2f(1000.0,170.0);
    glVertex2f(1000.0,280.0);
    glVertex2f(0.0,280.0);
    glEnd();
}
void NightRiverAndRoadsideArea()
{
    //glColor3ub(139,115,89);
    glColor3ub(0,26,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,170.0);
    glVertex2f(1000.0,170.0);
    glVertex2f(1000.0,280.0);
    glVertex2f(0.0,280.0);
    glEnd();
}

void Background()
{
    //glColor3ub(0, 128, 43);
    glColor3ub(105,139,34);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,470.0);
    glVertex2f(1000.0,470.0);
    glVertex2f(1000.0,830.0);
    glVertex2f(0.0,830.0);
    glEnd();
}

void NightBackground()
{
    //glColor3ub(0, 128, 43);
    glColor3ub(0,26,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,470.0);
    glVertex2f(1000.0,470.0);
    glVertex2f(1000.0,830.0);
    glVertex2f(0.0,830.0);
    glEnd();
}

void Hill()
{
    //3rd hill
    glPushMatrix();
    glTranslatef(90.0,0.0,0.0);
    glColor3ub(0 ,139, 69);
    glBegin(GL_TRIANGLES);
    glVertex2f(300.0,830.0);
    glVertex2f(450.0,830.0);
    glVertex2f(375.0,910.0);
    glEnd();

    glPopMatrix();

    //left 2nd hill
    glColor3ub(0 ,139, 69);
    glBegin(GL_TRIANGLES);
    glVertex2f(300.0,830.0);
    glVertex2f(450.0,830.0);
    glVertex2f(375.0,910.0);
    glEnd();

    //left 1st hill
    glPushMatrix();
    glTranslatef(-300.0,0.0,0.0);
    glColor3ub(0 ,139 ,69);
    glBegin(GL_TRIANGLES);
    glVertex2f(300.0,830.0);
    glVertex2f(450.0,830.0);
    glVertex2f(375.0,910.0);
    glEnd();

    glPopMatrix();

    //4th hill
    glPushMatrix();
    glTranslatef(400.0,0.0,0.0);
    glColor3ub(0, 139, 69);
    glBegin(GL_TRIANGLES);
    glVertex2f(300.0,830.0);
    glVertex2f(450.0,830.0);
    glVertex2f(375.0,910.0);
    glEnd();



    glPopMatrix();

}

void Villagehouse()
{
///ash color part
glColor3ub(105, 105, 105);
glBegin(GL_POLYGON);
glVertex2f(590.0,700.0);
glVertex2f(690.0,700.0);
glVertex2f(690.0,720.0);
glVertex2f(590.0,720.0);
glEnd();

///body part cream color
glColor3ub(240, 230, 140);
glBegin(GL_POLYGON);
glVertex2f(600.0,720.0);
glVertex2f(680.0,720.0);
glVertex2f(680.0,780.0);
glVertex2f(600.0,780.0);
glEnd();

///tin chocolate color
glColor3ub(210, 105, 30);
glBegin(GL_POLYGON);
glVertex2f(590.0,780.0);
glVertex2f(690.0,780.0);
glVertex2f(670.0,810.0);
glVertex2f(610.0,810.0);
glEnd();


///door
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(630.0,720.0);
glVertex2f(650.0,720.0);
glVertex2f(650.0,750.0);
glVertex2f(630.0,750.0);
glEnd();

///window
glColor3ub(138, 43, 226);
glBegin(GL_POLYGON);
glVertex2f(610.0,745.0);
glVertex2f(625.0,745.0);
glVertex2f(625.0,765.0);
glVertex2f(610.0,765.0);
glEnd();



glColor3ub(138, 43, 226);
glBegin(GL_POLYGON);
glVertex2f(655.0,745.0);
glVertex2f(670.0,745.0);
glVertex2f(670.0,765.0);
glVertex2f(655.0,765.0);
glEnd();
///window done


}
void Straw()
{
glColor3ub(230,172,0);
glBegin(GL_POLYGON);
glVertex2f(670.0,710.0);
glVertex2f(730.0,710.0);
glVertex2f(730.0,760.0);
glVertex2f(670.0,760.0);
glEnd();



glBegin(GL_POLYGON);
glColor3ub(230,172,0);
for(int i=0;i<200;i++)
{
float pi=3.1416;
float A=(i*2*pi)/200;
float r=25;
float x = 705+r * cos(A);
float y = 755+r * sin(A);
glVertex2f(x,y );
}
glEnd();



glColor3ub(139, 69, 0);
glBegin(GL_POLYGON);
glVertex2f(700.0,780.0);
glVertex2f(705.0,780.0);
glVertex2f(705.0,805.0);
glVertex2f(700.0,805.0);
glEnd();

}
void Hospital()
{
    glColor3ub(204, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(40,680);
    glVertex2f(40,510);
    glVertex2f(210,510);
    glVertex2f(210,680);
    glEnd();

    glColor3ub(204, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(80,740);
    glVertex2f(80,680);
    glVertex2f(170,680);
    glVertex2f(170,740);
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(80,780);
    glVertex2f(80,740);
    glVertex2f(170,740);
    glVertex2f(170,780);
    glEnd();

    glColor3ub(255, 255, 255);
    char *c="HOSPITAL";
    glRasterPos2f(102 , 755);
    for(int i = 0; c[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c[i]);

    glColor3ub(26, 26, 255);
    glBegin(GL_POLYGON);
    glVertex2f(76,730);
    glVertex2f(174,730);
    glVertex2f(174,740);
    glVertex2f(76,740);
    glEnd();

    glColor3ub(26, 26, 255);
    glBegin(GL_POLYGON);
    glVertex2f(36,680);
    glVertex2f(80,680);
    glVertex2f(80,690);
    glVertex2f(36,690);
    glEnd();

    glColor3ub(26, 26, 255);
    glBegin(GL_POLYGON);
    glVertex2f(170,680);
    glVertex2f(214,680);
    glVertex2f(214,690);
    glVertex2f(170,690);
    glEnd();

    ///hospital symbol
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=20;
		float x = 125+r * cos(A);
		float y = 700+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glLineWidth(4);
	glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2f(110,700);
    glVertex2f(140,700);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2f(125,715);
    glVertex2f(125,685);
    glEnd();
    ///symbol done

    ///left building window
    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(45,630);
    glVertex2f(55,630);
    glVertex2f(55,660);
    glVertex2f(45,660);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(65,630);
    glVertex2f(75,630);
    glVertex2f(75,660);
    glVertex2f(65,660);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(65,580);
    glVertex2f(75,580);
    glVertex2f(75,610);
    glVertex2f(65,610);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(45,580);
    glVertex2f(55,580);
    glVertex2f(55,610);
    glVertex2f(45,610);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(65,530);
    glVertex2f(75,530);
    glVertex2f(75,560);
    glVertex2f(65,560);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(45,530);
    glVertex2f(55,530);
    glVertex2f(55,560);
    glVertex2f(45,560);
    glEnd();
    ///done
    ///middle building Gate
    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(100,530);
    glVertex2f(120,530);
    glVertex2f(120,600);
    glVertex2f(100,600);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(130,530);
    glVertex2f(150,530);
    glVertex2f(150,600);
    glVertex2f(130,600);
    glEnd();
    ///done
    ///gate structure
    glColor3ub(255, 204, 255);
    glBegin(GL_POLYGON);
    glVertex2f(85,530);
    glVertex2f(92,530);
    glVertex2f(92,600);
    glVertex2f(85,600);
    glEnd();

    glColor3ub(255, 204, 255);
    glBegin(GL_POLYGON);
    glVertex2f(160,530);
    glVertex2f(167,530);
    glVertex2f(167,600);
    glVertex2f(160,600);
    glEnd();

    glColor3ub(255, 204, 255);
    glBegin(GL_POLYGON);
    glVertex2f(81,600);
    glVertex2f(172,600);
    glVertex2f(172,625);
    glVertex2f(81,625);
    glEnd();

    glColor3ub(26, 26, 255);
    glBegin(GL_POLYGON);
    glVertex2f(81,610);
    glVertex2f(172,610);
    glVertex2f(172,618);
    glVertex2f(81,618);
    glEnd();

    glColor3ub(255, 204, 255);
    glBegin(GL_POLYGON);
    glVertex2f(85,520);
    glVertex2f(167,520);
    glVertex2f(167,530);
    glVertex2f(85,530);
    glEnd();

    glColor3ub(255, 204, 255);
    glBegin(GL_POLYGON);
    glVertex2f(81,500);
    glVertex2f(171,500);
    glVertex2f(171,520);
    glVertex2f(81,520);
    glEnd();

    glColor3ub(255, 204, 255);
    glBegin(GL_POLYGON);
    glVertex2f(77,490);
    glVertex2f(175,490);
    glVertex2f(175,500);
    glVertex2f(77,500);
    glEnd();


    ///middle building window
    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(145,630);
    glVertex2f(155,630);
    glVertex2f(155,660);
    glVertex2f(145,660);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(120,630);
    glVertex2f(130,630);
    glVertex2f(130,660);
    glVertex2f(120,660);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(95,630);
    glVertex2f(105,630);
    glVertex2f(105,660);
    glVertex2f(95,660);
    glEnd();

    ///right building window
    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(175,630);
    glVertex2f(185,630);
    glVertex2f(185,660);
    glVertex2f(175,660);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(195,630);
    glVertex2f(205,630);
    glVertex2f(205,660);
    glVertex2f(195,660);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(175,580);
    glVertex2f(185,580);
    glVertex2f(185,610);
    glVertex2f(175,610);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(195,580);
    glVertex2f(205,580);
    glVertex2f(205,610);
    glVertex2f(195,610);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(175,530);
    glVertex2f(185,530);
    glVertex2f(185,560);
    glVertex2f(175,560);
    glEnd();

    glColor3ub(26, 140, 255);
    glBegin(GL_POLYGON);
    glVertex2f(195,530);
    glVertex2f(205,530);
    glVertex2f(205,560);
    glVertex2f(195,560);
    glEnd();
    ///done


}

void School()
{
glColor3ub(255, 43,15);
    glBegin(GL_POLYGON);
    glVertex2f(980,680);
    glVertex2f(980,500);
    glVertex2f(930,500);
    glVertex2f(930,680);
    glEnd();

    glColor3ub(255, 43,15);
    glBegin(GL_POLYGON);
    glVertex2f(928,680);
    glVertex2f(928,510);
    glVertex2f(810,510);
    glVertex2f(810,680);
    glEnd();

    ///name board
    glColor3ub(255, 112, 77);
    glBegin(GL_POLYGON);
    glVertex2f(860,680);
    glVertex2f(950,680);
    glVertex2f(950,740);
    glVertex2f(860,740);
    glEnd();

    glColor3ub(255, 255, 255);
    char *c="AIUB";
    glRasterPos2f(880.0 , 700.0);
    for(int i = 0; c[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);



///window
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(975,530);
    glVertex2f(960,530);
    glVertex2f(960,510);
    glVertex2f(975,510);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(975,590);
    glVertex2f(960,590);
    glVertex2f(960,570);
    glVertex2f(975,570);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(975,650);
    glVertex2f(960,650);
    glVertex2f(960,630);
    glVertex2f(975,630);
    glEnd();

     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(945,545);
    glVertex2f(932,545);
    glVertex2f(932,505);
    glVertex2f(945,505);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(945,605);
    glVertex2f(932,605);
    glVertex2f(932,565);
    glVertex2f(945,565);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(945,665);
    glVertex2f(932,665);
    glVertex2f(932,625);
    glVertex2f(945,625);
    glEnd();
    ///
     glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(925,650);
    glVertex2f(925,630);
    glVertex2f(915,630);
    glVertex2f(915,650);
    glEnd();

        glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(925,590);
    glVertex2f(925,570);
    glVertex2f(915,570);
    glVertex2f(915,590);
    glEnd();


     glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(925,540);
    glVertex2f(925,520);
    glVertex2f(915,520);
    glVertex2f(915,540);
    glEnd();

    glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(885,540);
    glVertex2f(885,510);
    glVertex2f(865,510);
    glVertex2f(865,540);
    glEnd();

    glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(880,590);
    glVertex2f(880,570);
    glVertex2f(870,570);
    glVertex2f(870,590);
    glEnd();

    glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(880,650);
    glVertex2f(880,630);
    glVertex2f(870,630);
    glVertex2f(870,650);
    glEnd();

    glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(840,650);
    glVertex2f(840,630);
    glVertex2f(830,630);
    glVertex2f(830,650);
    glEnd();

    glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(840,590);
    glVertex2f(840,570);
    glVertex2f(830,570);
    glVertex2f(830,590);
    glEnd();

    glColor3ub(255, 255,255);
    glBegin(GL_POLYGON);
    glVertex2f(840,540);
    glVertex2f(840,520);
    glVertex2f(830,520);
    glVertex2f(830,540);
    glEnd();

///line
glBegin(GL_POLYGON);
     glColor3ub(60,59,47);
    glVertex2f(852,680);
    glVertex2f(852,510);
    glVertex2f(848,510);
    glVertex2f(848,680);
    glEnd();

 glBegin(GL_POLYGON);
     glColor3ub(60,59,47);
    glVertex2f(900,680);
    glVertex2f(900,510);
    glVertex2f(896,510);
    glVertex2f(896,680);
    glEnd();

    //aaa
    glBegin(GL_POLYGON);

    glColor3ub(60,59,47);
    glVertex2f(928,510);
    glVertex2f(930,510);
    glVertex2f(930,690);
    glVertex2f(928,690);
    glEnd();

    glBegin(GL_POLYGON);
     glColor3ub(60,59,47);
    glVertex2f(806,690);
    glVertex2f(806,505);
    glVertex2f(810,505);
    glVertex2f(810,690);
    glEnd();

     glColor3ub(60, 59,47);
    glBegin(GL_POLYGON);
    glVertex2f(928,680);
    glVertex2f(928,690);
    glVertex2f(810,690);
    glVertex2f(810,680);
    glEnd();

     glColor3ub(60, 59,47);
    glBegin(GL_POLYGON);
    glVertex2f(930,680);
    glVertex2f(930,690);
    glVertex2f(985,690);
    glVertex2f(985,680);
    glEnd();

    glBegin(GL_POLYGON);
     glColor3ub(60,59,47);
    glVertex2f(985,690);
    glVertex2f(985,500);
    glVertex2f(980,500);
    glVertex2f(980,690);
    glEnd();

    glBegin(GL_POLYGON);
     glColor3ub(255, 43,15);
    glVertex2f(810,690);
    glVertex2f(810,710);
    glVertex2f(830,710);
    glVertex2f(830,690);
    glEnd();

   glBegin(GL_POLYGON);
      glColor3ub(60,59,47);
    glVertex2f(808,710);
    glVertex2f(808,715);
    glVertex2f(832,715);
    glVertex2f(832,710);
    glEnd();


    /// ground
    glBegin(GL_QUAD_STRIP);

    //glColor3ub(1, 155, 13);
    glColor3ub(184, 134 ,11);
    glVertex2f(986,500);
    glVertex2f(810,500);
    glVertex2f(986,490);
    glVertex2f(810,490);
    glEnd();

     //glColor3ub(1, 155,13);


    glColor3ub(184, 134 ,11);
    glBegin(GL_POLYGON);

    glVertex2f(800,490);
    glVertex2f(930,490);
    glVertex2f(930,510);
    glVertex2f(805,510);
    glEnd();
}

void Market ()
{
glColor3ub(254, 159, 141);
glBegin(GL_POLYGON);
glVertex2f(250,700);
glVertex2f(250,550);
glVertex2f(450,550);
glVertex2f(450,700);
glEnd();



glColor3ub(254, 142, 7);
glBegin(GL_POLYGON);
glVertex2f(250,540);
glVertex2f(250,550);
glVertex2f(453,550);
glVertex2f(453,540);
glEnd();








/// window



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(260,590);
glVertex2f(260,560);
glVertex2f(295,560);
glVertex2f(295,590);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(260,610);
glVertex2f(260,640);
glVertex2f(295,640);
glVertex2f(295,610);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(260,660);
glVertex2f(260,690);
glVertex2f(295,690);
glVertex2f(295,660);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(305,660);
glVertex2f(305,690);
glVertex2f(345,690);
glVertex2f(345,660);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(305,610);
glVertex2f(305,640);
glVertex2f(345,640);
glVertex2f(345,610);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(355,610);
glVertex2f(355,640);
glVertex2f(395,640);
glVertex2f(395,610);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(355,660);
glVertex2f(355,690);
glVertex2f(395,690);
glVertex2f(395,660);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(405,660);
glVertex2f(445,660);
glVertex2f(445,690);
glVertex2f(405,690);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(405,640);
glVertex2f(445,640);
glVertex2f(445,610);
glVertex2f(405,610);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(405,590);
glVertex2f(445,590);
glVertex2f(445,560);
glVertex2f(405,560);
glEnd();




///door
glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(355,550);
glVertex2f(355,600);
glVertex2f(390,600);
glVertex2f(390,550);
glEnd();



glColor3ub(141, 254, 234);
glBegin(GL_POLYGON);
glVertex2f(345,550);
glVertex2f(345,600);
glVertex2f(310,600);
glVertex2f(310,550);
glEnd();




///lines
glColor3ub(27, 31, 31);
glBegin(GL_POLYGON);
glVertex2f(390,605);
glVertex2f(390,600);
glVertex2f(310,600);
glVertex2f(310,605);
glEnd();



glColor3ub(27, 31, 31);
glBegin(GL_POLYGON);
glVertex2f(390,550);
glVertex2f(390,555);
glVertex2f(310,555);
glVertex2f(310,550);
glEnd();



glColor3ub(27, 31, 31);
glBegin(GL_POLYGON);
glVertex2f(385,600);
glVertex2f(385,555);
glVertex2f(390,555);
glVertex2f(390,600);
glEnd();



glColor3ub(27, 31, 31);
glBegin(GL_POLYGON);
glVertex2f(315,600);
glVertex2f(315,555);
glVertex2f(310,555);
glVertex2f(310,600);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(369,555);
glVertex2f(371,555);
glVertex2f(371,600);
glVertex2f(369,600);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(329,555);
glVertex2f(331,555);
glVertex2f(331,600);
glVertex2f(329,600);
glEnd();



glColor3ub(0, 247, 255);
glBegin(GL_POLYGON);
glVertex2f(250,707);
glVertex2f(250,700);
glVertex2f(450,700);
glVertex2f(450,707);
glEnd();

/// ground



//glColor3ub(100, 142, 4);
glColor3ub(184, 134 ,11);
glBegin(GL_POLYGON);
glVertex2f(230,500);
glVertex2f(250,540);
glVertex2f(453,540);
glVertex2f(453,500);
glEnd();



//glColor3ub(100, 142, 4);
glColor3ub(184, 134 ,11);
glBegin(GL_POLYGON);
glVertex2f(550,500);
glVertex2f(550,510);
glVertex2f(450,510);
glVertex2f(450,500);
glEnd();




}

void BigTree1()
{
        ///hos left side tree
    glPushMatrix();
    glTranslatef(-140.0,0.0,0.0);
    glColor3ub(160 ,82 ,45);
    glBegin(GL_POLYGON);
    glVertex2f(195.0,470.0);
    glVertex2f(205.0,470.0);
    glVertex2f(205.0,520.0);
    glVertex2f(195.0,520.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(165.0,530.0);
    glVertex2f(230.0,530.0);
    glVertex2f(200.0,570.0);
    glEnd();

    glColor3ub(0, 179, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(165.0,510.0);
    glVertex2f(230.0,510.0);
    glVertex2f(200.0,540.0);
    glEnd();
    glPopMatrix();
    ///done
}
void BigTree2()
{
///hos right side tree
    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2f(195.0,470.0);
    glVertex2f(205.0,470.0);
    glVertex2f(205.0,520.0);
    glVertex2f(195.0,520.0);
    glEnd();

    ///leaf
    glColor3ub(0, 179, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(165.0,530.0);
    glVertex2f(230.0,530.0);
    glVertex2f(200.0,570.0);
    glEnd();

    glColor3ub(0, 179, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(165.0,510.0);
    glVertex2f(230.0,510.0);
    glVertex2f(200.0,540.0);
    glEnd();
    ///done

}
void Hospitalsidetree()
{

    BigTree1();
    BigTree2();



}

void TestTrees()
{
 //Front two big tree
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(550,0,0);
 Hospitalsidetree();
 glPopMatrix();

//5th middle small
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(50,-200,0);
 Tree3();
 Tree4();
 glPopMatrix();

 //6th middle small
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(10,-190,0);
 Tree3();
 Tree4();
 glPopMatrix();


 //front small
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(85,-350,0);
 Tree3();
 glPopMatrix();

 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(25,-350,0);
 Tree4();
 glPopMatrix();

  //2nd front small
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(95,-300,0);
 Tree3();
 glPopMatrix();

   //2nd front small
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(140,-300,0);
 Tree3();
 glPopMatrix();
//cdd

 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(625,70,0);
 BigTree1();
 glPopMatrix();

    //3rd front small
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(180,-250,0);
 Tree3();
 glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(180,-180,0);
 Tree3();
 glPopMatrix();

     //3rd front small
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(40,-250,0);
 Tree3();
 glPopMatrix();



}
void Mosque()
{



glColor3ub(3, 90, 184);
glBegin(GL_POLYGON);
glVertex2f(550,700);
glVertex2f(550,510);
glVertex2f(453,510);
glVertex2f(453,700);
glEnd();



/// door
glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(490,560);
glVertex2f(490,520);
glVertex2f(510,520);
glVertex2f(510,560);
glVertex2f(500,570);
glEnd();



///window



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(475,560);
glVertex2f(475,530);
glVertex2f(460,530);
glVertex2f(460,560);
glVertex2f(467,570);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(475,620);
glVertex2f(475,590);
glVertex2f(460,590);
glVertex2f(460,620);
glVertex2f(467,630);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(475,680);
glVertex2f(475,650);
glVertex2f(460,650);
glVertex2f(460,680);
glVertex2f(467,690);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(493,680);
glVertex2f(493,650);
glVertex2f(507,650);
glVertex2f(507,680);
glVertex2f(500,690);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(493,620);
glVertex2f(493,590);
glVertex2f(507,590);
glVertex2f(507,620);
glVertex2f(500,630);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(525,620);
glVertex2f(525,590);
glVertex2f(539,590);
glVertex2f(539,620);
glVertex2f(532,630);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(525,680);
glVertex2f(525,650);
glVertex2f(539,650);
glVertex2f(539,680);
glVertex2f(532,690);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(525,560);
glVertex2f(525,530);
glVertex2f(539,530);
glVertex2f(539,560);
glVertex2f(532,570);
glEnd();



///done



glColor3ub(3, 90, 184);
glBegin(GL_POLYGON);
glVertex2f(530,730);
glVertex2f(530,700);
glVertex2f(550,700);
glVertex2f(550,730);
glVertex2f(540,745);
glEnd();



glColor3ub(3, 90, 184);
glBegin(GL_POLYGON);
glVertex2f(510,710);
glVertex2f(510,700);
glVertex2f(515,700);
glVertex2f(515,710);



glEnd();



glColor3ub(3, 90, 184);
glBegin(GL_POLYGON);
glVertex2f(490,710);
glVertex2f(490,700);
glVertex2f(495,700);
glVertex2f(495,710);
glEnd();



glColor3ub(3, 90, 184);
glBegin(GL_POLYGON);
glVertex2f(470,710);
glVertex2f(470,700);
glVertex2f(475,700);
glVertex2f(475,710);
glEnd();



glColor3ub(3, 90, 184);
glBegin(GL_POLYGON);
glVertex2f(453,710);
glVertex2f(453,700);
glVertex2f(458,700);
glVertex2f(458,710);
glEnd();



glColor3ub(3, 90, 184);
glBegin(GL_POLYGON);
glVertex2f(453,715);
glVertex2f(453,710);
glVertex2f(530,710);
glVertex2f(530,715);
glEnd();



///tree
glColor3ub(218,123,0);
glBegin(GL_POLYGON);
glVertex2f(555,505);
glVertex2f(555,525);
glVertex2f(560,525);
glVertex2f(560,505);
glEnd();



glColor3ub(0,142,4);
glBegin(GL_TRIANGLES);
glVertex2f(545,525);
glVertex2f(570,525);
glVertex2f(557,540);
glEnd();



glColor3ub(0,142,4);
glBegin(GL_TRIANGLES);
glVertex2f(545,535);
glVertex2f(570,535);
glVertex2f(557,550);
glEnd();



glColor3ub(0,142,4);
glBegin(GL_TRIANGLES);
glVertex2f(550,545);
glVertex2f(565,545);
glVertex2f(557,560);



glEnd();
}
void Road()
{
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,280.0);
    glVertex2f(1000.0,280.0);
    glVertex2f(1000.0,470.0);
    glVertex2f(0.0,470.0);
    glEnd();

    //glColor3ub(0, 0, 0);
    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,300.0);
    glVertex2f(1000.0,300.0);
    glVertex2f(1000.0,450.0);
    glVertex2f(0.0,450.0);
    glEnd();

///zebra crossing
glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(90.0,420.0);
glVertex2f(180.0,420.0);
glVertex2f(180.0,430.0);
glVertex2f(90.0,430.0);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(90.0,395.0);
glVertex2f(180.0,395.0);
glVertex2f(180.0,405.0);
glVertex2f(90.0,405.0);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(90.0,365.0);
glVertex2f(180.0,365.0);
glVertex2f(180.0,375.0);
glVertex2f(90.0,375.0);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(90.0,335.0);
glVertex2f(180.0,335.0);
glVertex2f(180.0,345.0);
glVertex2f(90.0,345.0);
glEnd();



glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2f(90.0,310.0);
glVertex2f(180.0,310.0);
glVertex2f(180.0,320.0);
glVertex2f(90.0,320.0);
glEnd();
///zebra crossing done

    glLineWidth(2);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2f(0.0,375.0);
    glVertex2f(1000.0,375.0);
    glEnd();

    //side white red shadow
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,280.0);
    glVertex2f(30.0,280.0);
    glVertex2f(30.0,300.0);
    glVertex2f(0.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(60.0,280.0);
    glVertex2f(90.0,280.0);
    glVertex2f(90.0,300.0);
    glVertex2f(60.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(120.0,280.0);
    glVertex2f(150.0,280.0);
    glVertex2f(150.0,300.0);
    glVertex2f(120.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(180.0,280.0);
    glVertex2f(210.0,280.0);
    glVertex2f(210.0,300.0);
    glVertex2f(180.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(240.0,280.0);
    glVertex2f(270.0,280.0);
    glVertex2f(270.0,300.0);
    glVertex2f(240.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(300.0,280.0);
    glVertex2f(330.0,280.0);
    glVertex2f(330.0,300.0);
    glVertex2f(300.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(360.0,280.0);
    glVertex2f(390.0,280.0);
    glVertex2f(390.0,300.0);
    glVertex2f(360.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(420.0,280.0);
    glVertex2f(450.0,280.0);
    glVertex2f(450.0,300.0);
    glVertex2f(420.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(480.0,280.0);
    glVertex2f(510.0,280.0);
    glVertex2f(510.0,300.0);
    glVertex2f(480.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(540.0,280.0);
    glVertex2f(570.0,280.0);
    glVertex2f(570.0,300.0);
    glVertex2f(540.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(600.0,280.0);
    glVertex2f(630.0,280.0);
    glVertex2f(630.0,300.0);
    glVertex2f(600.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(660.0,280.0);
    glVertex2f(690.0,280.0);
    glVertex2f(690.0,300.0);
    glVertex2f(660.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(720.0,280.0);
    glVertex2f(750.0,280.0);
    glVertex2f(750.0,300.0);
    glVertex2f(720.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(780.0,280.0);
    glVertex2f(810.0,280.0);
    glVertex2f(810.0,300.0);
    glVertex2f(780.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(840.0,280.0);
    glVertex2f(870.0,280.0);
    glVertex2f(870.0,300.0);
    glVertex2f(840.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(900.0,280.0);
    glVertex2f(930.0,280.0);
    glVertex2f(930.0,300.0);
    glVertex2f(900.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(960.0,280.0);
    glVertex2f(990.0,280.0);
    glVertex2f(990.0,300.0);
    glVertex2f(960.0,300.0);
    glEnd();

    glPushMatrix();
    glTranslatef(0.0f,170.0f,0.0f);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,280.0);
    glVertex2f(30.0,280.0);
    glVertex2f(30.0,300.0);
    glVertex2f(0.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(60.0,280.0);
    glVertex2f(90.0,280.0);
    glVertex2f(90.0,300.0);
    glVertex2f(60.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(120.0,280.0);
    glVertex2f(150.0,280.0);
    glVertex2f(150.0,300.0);
    glVertex2f(120.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(180.0,280.0);
    glVertex2f(210.0,280.0);
    glVertex2f(210.0,300.0);
    glVertex2f(180.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(240.0,280.0);
    glVertex2f(270.0,280.0);
    glVertex2f(270.0,300.0);
    glVertex2f(240.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(300.0,280.0);
    glVertex2f(330.0,280.0);
    glVertex2f(330.0,300.0);
    glVertex2f(300.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(360.0,280.0);
    glVertex2f(390.0,280.0);
    glVertex2f(390.0,300.0);
    glVertex2f(360.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(420.0,280.0);
    glVertex2f(450.0,280.0);
    glVertex2f(450.0,300.0);
    glVertex2f(420.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(480.0,280.0);
    glVertex2f(510.0,280.0);
    glVertex2f(510.0,300.0);
    glVertex2f(480.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(540.0,280.0);
    glVertex2f(570.0,280.0);
    glVertex2f(570.0,300.0);
    glVertex2f(540.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(600.0,280.0);
    glVertex2f(630.0,280.0);
    glVertex2f(630.0,300.0);
    glVertex2f(600.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(660.0,280.0);
    glVertex2f(690.0,280.0);
    glVertex2f(690.0,300.0);
    glVertex2f(660.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(720.0,280.0);
    glVertex2f(750.0,280.0);
    glVertex2f(750.0,300.0);
    glVertex2f(720.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(780.0,280.0);
    glVertex2f(810.0,280.0);
    glVertex2f(810.0,300.0);
    glVertex2f(780.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(840.0,280.0);
    glVertex2f(870.0,280.0);
    glVertex2f(870.0,300.0);
    glVertex2f(840.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(900.0,280.0);
    glVertex2f(930.0,280.0);
    glVertex2f(930.0,300.0);
    glVertex2f(900.0,300.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(960.0,280.0);
    glVertex2f(990.0,280.0);
    glVertex2f(990.0,300.0);
    glVertex2f(960.0,300.0);
    glEnd();
    glPopMatrix();

}
void Car_1_wheel_1()
{
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(535,410,0);
 glRotatef(c1_WheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-530,-410,0);
    glBegin(GL_POLYGON);
    glColor3ub(0, 51, 128);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = 530+r * cos(A);
		float y = 410+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

glLineWidth(2.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(530,395);
glVertex2f(530,425);
glEnd();

glLineWidth(2.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(515,410);
glVertex2f(545,410);
glEnd();

glPopMatrix();

}
void Car_1_wheel_2()
{
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(605,410,0);
 glRotatef(c1_WheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-600,-410,0);

glBegin(GL_POLYGON);
glColor3ub(0, 51, 128);
for(int i=0;i<200;i++)
 {
    float pi=3.1416;
    float A=(i*2*pi)/200;
    float r=15;
    float x = 600+r * cos(A);
    float y = 410+r * sin(A);
    glVertex2f(x,y );
 }
glEnd();

glLineWidth(2.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(600,395);
glVertex2f(600,425);
glEnd();

glLineWidth(2.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(585,410);
glVertex2f(615,410);
glEnd();

glPopMatrix();
}

void Car_2_wheel_1()
{
     glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(605,310,0);
 glRotatef(c2_WheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-600,-310,0);

    glBegin(GL_POLYGON);
    glColor3ub(0, 51, 128);
    for(int i=0;i<200;i++)
    {
    float pi=3.1416;
    float A=(i*2*pi)/200;
    float r=15;
    float x = 600+r * cos(A);
    float y = 310+r * sin(A);
    glVertex2f(x,y );
    }
    glEnd();

    	glLineWidth(2.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(600,295);
glVertex2f(600,325);
glEnd();

glLineWidth(2.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(585,310);
glVertex2f(615,310);
glEnd();
glPopMatrix();
}
void Car_2_wheel_2()
{
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(535,310,0);
 glRotatef(c2_WheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-530,-310,0);

    glBegin(GL_POLYGON);
    glColor3ub(0, 51, 128);
    for(int i=0;i<200;i++)
    {
    float pi=3.1416;
    float A=(i*2*pi)/200;
    float r=15;
    float x = 530+r * cos(A);
    float y = 310+r * sin(A);
    glVertex2f(x,y );
    }
    glEnd();

    glLineWidth(2.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(530,295);
glVertex2f(530,325);
glEnd();

glLineWidth(2.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(515,310);
glVertex2f(545,310);
glEnd();
glPopMatrix();
}
void car1()
{
    glPushMatrix();
    glTranslatef(position_car1,0.0, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 64, 0);
    glVertex2f(500,410);
    glVertex2f(640,410);
    glVertex2f(640,440);
    glVertex2f(500,440);
    glEnd();

	//wheel done
	glBegin(GL_POLYGON);
    glColor3ub(255, 64, 0);
    glVertex2f(520,440);
    glVertex2f(640,440);
    glVertex2f(620,470);
    glVertex2f(535,470);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(520,440);
    glVertex2f(640,440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 204);
    glVertex2f(530,440);
    glVertex2f(580,440);
    glVertex2f(580,465);
    glVertex2f(540,465);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 204);
    glVertex2f(585,440);
    glVertex2f(630,440);
    glVertex2f(615,465);
    glVertex2f(585,465);
    glEnd();
    Car_1_wheel_1();
    Car_1_wheel_2();

    glPopMatrix();

}
void car2()
{
    glPushMatrix();
    glTranslatef(position_car2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 204);
    glVertex2f(500,310);
    glVertex2f(640,310);
    glVertex2f(640,340);
    glVertex2f(500,340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 64, 0);
    glVertex2f(500,340);
    glVertex2f(625,340);
    glVertex2f(615,370);
    glVertex2f(515,370);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(510,340);
    glVertex2f(630,340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 204);
    glVertex2f(510,340);
    glVertex2f(580,340);
    glVertex2f(580,365);
    glVertex2f(520,365);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 204);
    glVertex2f(585,340);
    glVertex2f(620,340);
    glVertex2f(610,365);
    glVertex2f(585,365);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(500,310);
    glVertex2f(640,310);
    glVertex2f(640,340);
    glVertex2f(500,340);
    glEnd();

    Car_2_wheel_1();
    Car_2_wheel_2();


    glPopMatrix();
}
void Railway()
{
 //under rail line color
 glColor3ub(150, 150, 144);
 SquareShape(0,180,1000,180,1000,205,0,205);

 //railway upper line
 glColor3ub(0, 0, 0);
 SquareShape(0,202,1000,202,1000,205,0,205);

 //railway lower line
 glColor3ub(0, 0, 0);
 SquareShape(0,180,1000,180,1000,184,0,184);

 //rail lines between two main line
 glColor3ub(0, 0, 0);
 glBegin(GL_LINES);
 float j;
 for(j=0;j<=1000;j+=20)
  {
     glVertex2f(10+j,180);
     glVertex2f(15+j,205);
  }
 glEnd();

}

void TrainWheel(float p)
{
    glBegin(GL_POLYGON);
    glColor3ub(77, 38, 0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = p+r * cos(A);
		float y = 192+r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
}
void WheelLine(float p, float q, float x, float y)
{
glLineWidth(1.0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(p,q);
glVertex2f(x,y);
glEnd();

}
void TrainWheels()
{

 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(45,192,0);
 glRotatef(trainWheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-40,-192,0);

 //1st bogi-1st wheel
 TrainWheel(40);
 WheelLine(40,182,40,201);
 WheelLine(30,190,50,190);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(85,192,0);
 glRotatef(trainWheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-80,-192,0);
 //1st bogi-2nd wheel
 TrainWheel(80);
 WheelLine(80,182,80,201);
 WheelLine(70,190,90,190);
 glPopMatrix();

 //glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(120,192,0);
 glRotatef(trainWheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-115,-192,0);

 //2nd bogi-1st wheel
 TrainWheel(115);
 WheelLine(115,182,115,201);
 WheelLine(105,190,125,190);
 glPopMatrix();

 //glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glTranslatef(160,192,0);
 glRotatef(trainWheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-155,-192,0);
 //2nd bogi-2nd wheel
 TrainWheel(155);
 WheelLine(155,182,155,201);
 WheelLine(145,190,165,190);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(195,192,0);
 glRotatef(trainWheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-190,-192,0);
 //3rd bogi-1st wheel
 TrainWheel(190);
 WheelLine(190,182,190,201);
 WheelLine(180,190,200,190);
 glPopMatrix();

glPushMatrix();
 glTranslatef(235,192,0);
 glRotatef(trainWheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-230,-192,0);
 //3rd bogi-2nd wheel
 TrainWheel(230);
 WheelLine(230,182,230,201);
 WheelLine(220,190,240,190);
  glPopMatrix();

  glPushMatrix();
 glTranslatef(270,192,0);
 glRotatef(trainWheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-265,-192,0);
 //engine bodi-1st wheel
 TrainWheel(265);
 WheelLine(265,182,265,201);
 WheelLine(255,190,275,190);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(310,192,0);
 glRotatef(trainWheelAngle1,0.0f, 0.0f, 1.0f);
 glTranslatef(-305,-192,0);
 //engine bodi-2nd wheel
 TrainWheel(305);
 WheelLine(305,182,305,201);
 WheelLine(295,190,315,190);
 glPopMatrix();
}
void TrainSmoke(float p, float q,float x)
{
 glBegin(GL_POLYGON);
 glColor3ub(191, 191, 191);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=x;
		float x = p+r * cos(A);
		float y = q+r * sin(A);
		glVertex2f(x,y );
	}
 glEnd();

}

void Train()
{
 glPushMatrix();
 glTranslatef(trainSpeed, 0.0f, 0.0f);

 //2nd bogi green box
 glColor3ub(0, 102, 0);//green color
 SquareShape(100,200,170,200,170,250,100,250);
 //2nd Bogi 1st window.
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(110,225,120,225,120,240,110,240);
 //2nd Bogi 2nd window.
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(130,225,140,225,140,240,130,240);
 //2nd Bogi 3rd window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(150,225,160,225,160,240,150,240);
 //2nd bogi red line
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(100,210,170,210,170,215,100,215);
 //2nd bogi front side
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(170,200,176,210,176,260,170,250);
 //2nd bogi top side
 glColor3f(1.0, 0.0, 0.0);//red color
 SquareShape(101,250,170,250,176,260,105,260);

 glPushMatrix();
 glTranslatef(75, 0, 0);
 //3rd bogi green box
 glColor3ub(0, 102, 0);
 SquareShape(100,200,170,200,170,250,100,250);
 //3rd bogi 1st window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(110,225,120,225,120,240,110,240);
 //3rd bogi 2nd window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(130,225,140,225,140,240,130,240);
 //3rd bogi 3rd window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(150,225,160,225,160,240,150,240);
 //3rd body red line
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(100,210,170,210,170,215,100,215);
 //3rd bogi front side
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(170,200,176,210,176,260,170,250);
 //3rd bogi top side
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(101,250,170,250,176,260,105,260);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-75, 0, 0);
 //1st bogi green box
 glColor3ub(0, 102, 0);
 SquareShape(100,200,170,200,170,250,100,250);
 //1st bogi 1st window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(110,225,120,225,120,240,110,240);
 //1st bogi 2nd window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(130,225,140,225,140,240,130,240);
 //1st bogi 3rd window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(150,225,160,225,160,240,150,240);
 //1st bogi red line
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(100,210,170,210,170,215,100,215);
 //1st bogi front side
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(170,200,176,210,176,260,170,250);
 //1st bogi top side
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(101,250,170,250,176,260,105,260);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(150, 0, 0);
 //Engine bogi green box
 glColor3ub(0, 102, 0);
 SquareShape(100,200,170,200,170,250,100,250);
 //Engine bogi 1st window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(110,225,120,225,120,240,110,240);
 //Engine bogi 2nd window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(130,225,140,225,140,240,130,240);
 //Engine bogi 3rd window
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(150,225,160,225,160,240,150,240);
 //Engine bogi red line
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(100,210,170,210,170,215,100,215);
 //Engine bogi front side
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(170,200,176,210,176,260,170,250);
 //Engine bogi top side
 glColor3f(1.0, 0.0, 0.0);
 SquareShape(101,250,170,250,176,260,105,260);
 glPopMatrix();
 //engine bogi front box
 glColor3ub(0, 102, 0);
 SquareShape(322,245,330,245,330,232,322,232);
 //Engine bogi smoke hole
 glColor3f(1.0, 1.0, 1.0);
 SquareShape(310,253,300,253,300,258,310,258);
 //engine bogi 1st smoke
 TrainSmoke(303,267,3);
 //Engine bogi 2nd smoke
 TrainSmoke(293,270,4);
 //Engine bogi 3rd(Big) smoke
 TrainSmoke(283,272,5);

 TrainWheels();

 glPopMatrix();

}

void UpdateCar_1Wheel(int x) {
 if(c1_stop)
 {
   c1_WheelAngle1 +=5.0f;
   if(c1_WheelAngle1 > 360.0)
    {
    c1_WheelAngle1-=360;
    }

   glutPostRedisplay();
   glutTimerFunc(20, UpdateCar_1Wheel, 0);
 }

}

void Car_1_Backward(int value) {
    if(c1_backward)
    {
        position_car1 += 2.50f;
        if(position_car1>500)
         {
           position_car1=-650;
         }
    }

glutPostRedisplay();
glutTimerFunc(25, Car_1_Backward, 0);
}

void Car_1_Forward(int value){
if(c1_forward){

    position_car1 -= 2.0f;

     if (position_car1 < -650)
        {
		position_car1 = 600;
	    }
	glutPostRedisplay();
	glutTimerFunc(25, Car_1_Forward, 0);
}
}

void UpdateCar_2Wheel(int value) {
if(c2_stop)
 {
   c2_WheelAngle1+=5.0f;
   if(c2_WheelAngle1 > 360.0)
    {
    c2_WheelAngle1-=360;
    }

   glutPostRedisplay();
   glutTimerFunc(20, UpdateCar_2Wheel, 0);
 }
}

void Car_2_Forward(int value) {
    if(c2_forward)
    {
        position_car2 += 2.50f;
        if(position_car2>600)
         {
           position_car2=-700;
         }
    }

glutPostRedisplay();
glutTimerFunc(25, Car_2_Forward, 0);
}

void Car_2_Backward(int value){
if(c2_backward){

    position_car2 -= 2.0f;

     if (position_car2 < -700)
        {
		position_car2 = 600;
	    }
	glutPostRedisplay();
	glutTimerFunc(25, Car_2_Backward, 0);
}
}


void UpdateTrainWheelPosition(int x) {
if(t_stop)
{
    trainWheelAngle1+=10.0f;

if(trainWheelAngle1 > 360.0)
{
  trainWheelAngle1-=360;
}

glutPostRedisplay();
glutTimerFunc(20, UpdateTrainWheelPosition, 0);
}

}
void TrainForward(int value) {
    if(t_forward)
    {
        trainSpeed += 2.50f;
        if(trainSpeed>1000)
         {
           trainSpeed=-350;
         }
    }

glutPostRedisplay();
glutTimerFunc(25, TrainForward, 0);
}

void TrainBackward(int value){
if(t_backword){

    trainSpeed -= 2.0f;

     if (trainSpeed < -350)
        {
		trainSpeed = 1100;
	    }
	glutPostRedisplay();
	glutTimerFunc(25, TrainBackward, 0);
}
}

void River()
{
    //railway side border
    glColor3ub(153, 115, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,175.0);
    glVertex2f(1000.0,175.0);
    glVertex2f(1000.0,130.0);
    glVertex2f(0.0,130.0);
    glEnd();

    //DESIGN
    glColor3ub(184 ,134, 11);
    glBegin(GL_POLYGON);
    glVertex2f(0,130);
    glVertex2f(10,160);
    glVertex2f(60,120);
    glVertex2f(100,170);
    glVertex2f(150,140);
    glVertex2f(200,130);
    glVertex2f(300,130);
    glVertex2f(310,130);
    glVertex2f(330,120);
    glVertex2f(340,170);
    glVertex2f(420,120);
    glVertex2f(460,120);
    glVertex2f(550,130);
    glVertex2f(570,170);
    glVertex2f(600,130);
    glVertex2f(650,160);
    glVertex2f(700,140);
    glVertex2f(750,170);
    glVertex2f(850,120);
    glVertex2f(900,170);
    glVertex2f(1000,140);
    glEnd();


    //river with water
   glColor3ub(102, 179, 255);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,0.0);
    glVertex2f(1000.0,0.0);
    glVertex2f(1000.0,130.0);
    glVertex2f(0.0,130.0);
    glEnd();
}

void NightRiver()
{
     glColor3ub(153, 115, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,170.0);
    glVertex2f(1000.0,170.0);
    glVertex2f(1000.0,130.0);
    glVertex2f(0.0,130.0);
    glEnd();

    glColor3ub(153, 115, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,170.0);
    glVertex2f(1000.0,170.0);
    glVertex2f(1000.0,130.0);
    glVertex2f(0.0,130.0);
    glEnd();

    glColor3ub(0, 0, 77);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,0.0);
    glVertex2f(1000.0,0.0);
    glVertex2f(1000.0,130.0);
    glVertex2f(0.0,130.0);
    glEnd();
}
void Boat_1()
{
    glPushMatrix();
    glTranslatef(position_boat1,0.0f, 0.0f);
    //back round shape
    glBegin(GL_POLYGON);
    for(int i=0;i<70;i++)
    {
        glColor3ub(230, 172, 0);
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=30;
        float x = 350+r * cos(A);
        float y = 70+r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
 //top brown shape
    glColor3ub(230, 172, 0);
    glBegin(GL_POLYGON);
    glVertex2f(230.0,60.0);
    glVertex2f(350.0,60.0);
    glVertex2f(350.0,100.0);
    glVertex2f(230.0,100.0);
    glEnd();
 //front round shape
    glBegin(GL_POLYGON);
    for(int i=0;i<38;i++)
    {
        glColor3ub(153, 77, 0);
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=60;
        float x = 220+r * cos(A);
        float y = 39+r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    //front black shape
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(140.0,120.0);
    glVertex2f(230.0,60.0);
    glVertex2f(230.0,40.0);
    glEnd();

  //bottom black shape
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(230.0,40.0);
    glVertex2f(350.0,40.0);
    glVertex2f(350.0,60.0);
    glVertex2f(230.0,60.0);
    glEnd();

    //back black shape
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(440.0,120.0);
    glVertex2f(350.0,60.0);
    glVertex2f(350.0,40.0);
    glEnd();
    glPopMatrix();
}

void Boat_2()
{
   glPushMatrix();
    glTranslatef(position_boat2,0.0f, 0.0f);

    //back round shape
    glBegin(GL_POLYGON);
    for(int i=0;i<70;i++)
    {
        glColor3ub(230, 172, 0);
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=30;
        float x = 850+r * cos(A);
        float y = 60+r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
 //top brown shape
    glColor3ub(230, 172, 0);
    glBegin(GL_POLYGON);
    glVertex2f(730.0,50.0);
    glVertex2f(850.0,50.0);
    glVertex2f(850.0,90.0);
    glVertex2f(730.0,90.0);
    glEnd();

    //front round shape
    glBegin(GL_POLYGON);
    for(int i=0;i<38;i++)
    {
        glColor3ub(153, 77, 0);
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=60;
        float x = 720+r * cos(A);
        float y = 29+r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


//front black shape
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(640.0,110.0);
    glVertex2f(730.0,50.0);
    glVertex2f(730.0,30.0);
    glEnd();

    //bottom back shape
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(730.0,30.0);
    glVertex2f(850.0,30.0);
    glVertex2f(850.0,50.0);
    glVertex2f(730.0,50.0);
    glEnd();

    //back black shape
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(940.0,110.0);
    glVertex2f(850.0,50.0);
    glVertex2f(850.0,30.0);
    glEnd();
    glPopMatrix();
}


void BoatForward(int x)
{

    if(b_forward)
    {
        position_boat1 += 2.50f;
        if(position_boat1>850)
           {
            position_boat1=-800;
           }
        position_boat2 -= 2.0f;

        if(position_boat2 < -950)
           {
		    position_boat2 = 500;
	       }
    }

glutPostRedisplay();
glutTimerFunc(25, BoatForward, 0);
}

void BoatBackward(int x)
{

    if(b_backward)
    {
        position_boat2 += 2.50f;
        if(position_boat2>550)
           {
            position_boat2=-900;
           }
        position_boat1 -= 2.0f;

        if(position_boat1 < -600)
           {
		    position_boat1 = 850;
	       }
    }

glutPostRedisplay();
glutTimerFunc(25, BoatBackward, 0);
}

void UpdateCloud1(int value)
{
    cloud1_position += 10;
    if(cloud1_position > 1000)
    {
        cloud1_position = -200.0f;
    }

	glutPostRedisplay();

	glutTimerFunc(25, UpdateCloud1, 0);
}
void UpdateCloud2(int value)
{
    cloud2_position += 2;
    if(cloud2_position > 1000)
    {
        cloud2_position = -600.0f;
    }

	glutPostRedisplay();

	glutTimerFunc(25, UpdateCloud2, 0);
}

void UpdateCloud3(int value)
{
    cloud3_position -= 5;
    if(cloud3_position <-1000)
    {
        cloud3_position = 200.0f;
    }

	glutPostRedisplay();

	glutTimerFunc(25, UpdateCloud3, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

  Sky();
    Sun();
   RiverAndRoadsideArea();
   Background();

    //glMatrixMode(GL_MODELVIEW);
Railway();
    Train();

    Road();

    car1();
    car2();

    River();
    Boat_1();
    Boat_2();

    Cloud1();
    Cloud2();
    Cloud3();
    TreeWithHill();

    Hill();
    Hospital();
    School();
    Market();
    Mosque();
    Hospitalsidetree();
    Straw();
    Villagehouse();
    TestTrees();



    glFlush();
    glutSwapBuffers();

}

void Door()
{
    ///mosque
    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(490,560);
    glVertex2f(490,520);
    glVertex2f(510,520);
    glVertex2f(510,560);
     glVertex2f(500,570);
    glEnd();

  glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(475,560);
    glVertex2f(475,530);
    glVertex2f(460,530);
    glVertex2f(460,560);
    glVertex2f(467,570);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(475,620);
    glVertex2f(475,590);
    glVertex2f(460,590);
    glVertex2f(460,620);
    glVertex2f(467,630);
    glEnd();

     glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(475,680);
    glVertex2f(475,650);
    glVertex2f(460,650);
    glVertex2f(460,680);
     glVertex2f(467,690);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(493,680);
    glVertex2f(493,650);
    glVertex2f(507,650);
    glVertex2f(507,680);
     glVertex2f(500,690);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(493,620);
    glVertex2f(493,590);
    glVertex2f(507,590);
    glVertex2f(507,620);
     glVertex2f(500,630);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(525,620);
    glVertex2f(525,590);
    glVertex2f(539,590);
    glVertex2f(539,620);
     glVertex2f(532,630);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(525,680);
    glVertex2f(525,650);
    glVertex2f(539,650);
    glVertex2f(539,680);
     glVertex2f(532,690);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(525,560);
    glVertex2f(525,530);
    glVertex2f(539,530);
    glVertex2f(539,560);
     glVertex2f(532,570);
    glEnd();

    /// market

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(260,590);
    glVertex2f(260,560);
    glVertex2f(295,560);
    glVertex2f(295,590);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(260,610);
    glVertex2f(260,640);
    glVertex2f(295,640);
    glVertex2f(295,610);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(260,660);
    glVertex2f(260,690);
    glVertex2f(295,690);
    glVertex2f(295,660);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(305,660);
    glVertex2f(305,690);
    glVertex2f(345,690);
    glVertex2f(345,660);
    glEnd();

     glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(305,610);
    glVertex2f(305,640);
    glVertex2f(345,640);
    glVertex2f(345,610);
    glEnd();

     glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(355,610);
    glVertex2f(355,640);
    glVertex2f(395,640);
    glVertex2f(395,610);
    glEnd();

      glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(355,660);
    glVertex2f(355,690);
    glVertex2f(395,690);
    glVertex2f(395,660);
    glEnd();

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(405,660);
    glVertex2f(445,660);
    glVertex2f(445,690);
    glVertex2f(405,690);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(405,640);
    glVertex2f(445,640);
    glVertex2f(445,610);
    glVertex2f(405,610);
    glEnd();

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(405,590);
    glVertex2f(445,590);
    glVertex2f(445,560);
    glVertex2f(405,560);
    glEnd();


    ///door
        glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(355,550);
    glVertex2f(355,600);
    glVertex2f(390,600);
    glVertex2f(390,550);
    glEnd();

           glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(345,550);
    glVertex2f(345,600);
    glVertex2f(310,600);
    glVertex2f(310,550);
    glEnd();

    ///School

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(975,530);
    glVertex2f(960,530);
    glVertex2f(960,510);
    glVertex2f(975,510);
    glEnd();

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(975,590);
    glVertex2f(960,590);
    glVertex2f(960,570);
    glVertex2f(975,570);
    glEnd();

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(975,650);
    glVertex2f(960,650);
    glVertex2f(960,630);
    glVertex2f(975,630);
    glEnd();

     glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(945,545);
    glVertex2f(932,545);
    glVertex2f(932,505);
    glVertex2f(945,505);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(945,605);
    glVertex2f(932,605);
    glVertex2f(932,565);
    glVertex2f(945,565);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(945,665);
    glVertex2f(932,665);
    glVertex2f(932,625);
    glVertex2f(945,625);
    glEnd();
    ///
     glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(925,650);
    glVertex2f(925,630);
    glVertex2f(915,630);
    glVertex2f(915,650);
    glEnd();
glColor3ub(255, 238, 35);

    glBegin(GL_POLYGON);
    glVertex2f(925,590);
    glVertex2f(925,570);
    glVertex2f(915,570);
    glVertex2f(915,590);
    glEnd();


     glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(925,540);
    glVertex2f(925,520);
    glVertex2f(915,520);
    glVertex2f(915,540);
    glEnd();

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(885,540);
    glVertex2f(885,510);
    glVertex2f(865,510);
    glVertex2f(865,540);
    glEnd();

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(880,590);
    glVertex2f(880,570);
    glVertex2f(870,570);
    glVertex2f(870,590);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(880,650);
    glVertex2f(880,630);
    glVertex2f(870,630);
    glVertex2f(870,650);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(840,650);
    glVertex2f(840,630);
    glVertex2f(830,630);
    glVertex2f(830,650);
    glEnd();
glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(840,590);
    glVertex2f(840,570);
    glVertex2f(830,570);
    glVertex2f(830,590);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(840,540);
    glVertex2f(840,520);
    glVertex2f(830,520);
    glVertex2f(830,540);
    glEnd();


    ///hospital

       ///middle building window
       glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(145,630);
    glVertex2f(155,630);
    glVertex2f(155,660);
    glVertex2f(145,660);
    glEnd();

       glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(120,630);
    glVertex2f(130,630);
    glVertex2f(130,660);
    glVertex2f(120,660);
    glEnd();

       glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(95,630);
    glVertex2f(105,630);
    glVertex2f(105,660);
    glVertex2f(95,660);
    glEnd();

    ///right building window
       glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(175,630);
    glVertex2f(185,630);
    glVertex2f(185,660);
    glVertex2f(175,660);
    glEnd();

       glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(195,630);
    glVertex2f(205,630);
    glVertex2f(205,660);
    glVertex2f(195,660);
    glEnd();

       glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(175,580);
    glVertex2f(185,580);
    glVertex2f(185,610);
    glVertex2f(175,610);
    glEnd();

      glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(195,580);
    glVertex2f(205,580);
    glVertex2f(205,610);
    glVertex2f(195,610);
    glEnd();

       glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(175,530);
    glVertex2f(185,530);
    glVertex2f(185,560);
    glVertex2f(175,560);
    glEnd();

       glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(195,530);
    glVertex2f(205,530);
    glVertex2f(205,560);
    glVertex2f(195,560);
    glEnd();

      ///middle building Gate
   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(100,530);
    glVertex2f(120,530);
    glVertex2f(120,600);
    glVertex2f(100,600);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(130,530);
    glVertex2f(150,530);
    glVertex2f(150,600);
    glVertex2f(130,600);
    glEnd();

      ///left building window
   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(45,630);
    glVertex2f(55,630);
    glVertex2f(55,660);
    glVertex2f(45,660);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(65,630);
    glVertex2f(75,630);
    glVertex2f(75,660);
    glVertex2f(65,660);
    glEnd();

    glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(65,580);
    glVertex2f(75,580);
    glVertex2f(75,610);
    glVertex2f(65,610);
    glEnd();

     glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(45,580);
    glVertex2f(55,580);
    glVertex2f(55,610);
    glVertex2f(45,610);
    glEnd();

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(65,530);
    glVertex2f(75,530);
    glVertex2f(75,560);
    glVertex2f(65,560);
    glEnd();

   glColor3ub(255, 238, 35);
    glBegin(GL_POLYGON);
    glVertex2f(45,530);
    glVertex2f(55,530);
    glVertex2f(55,560);
    glVertex2f(45,560);
    glEnd();


}
void Night()
{
    glClear(GL_COLOR_BUFFER_BIT);

    NightRiver();
    NightBackground();
    NightRiverAndRoadsideArea();
    Road();
    car1();
    car2();
    NightSky();
    Hill();
    Moon();
    NightCloud1();
    //NightCloud2();
    NightCloud3();
    Hospital();

    School();
    Straw();
    Villagehouse();
    Market();
    Mosque();
    Door();
    TestTrees();
     Hospitalsidetree();

    Boat_1();
    Boat_2();
    Railway();
    Train();
    glFlush();


}
void handleKeypress(unsigned char key, int x, int y) {

switch (key) {
case 'f':
    t_forward=true;
    t_backword=false;
    t_stop=true;
    UpdateTrainWheelPosition(2);
    TrainForward(trainSpeed);
    break;
case 'b':
    t_forward=false;
    t_backword=true;
    t_stop=true;
    UpdateTrainWheelPosition(2);
    TrainBackward(trainSpeed);
    break;
case 's':
    t_forward=false;
    t_backword=false;
    t_stop=false;
    break;

case 'o':
    c1_forward=false;
    c1_backward=true;
    c1_stop=true;
    UpdateCar_1Wheel(2);
    Car_1_Backward(position_car1);
    break;
case 'p':
    c1_forward=true;
    c1_backward=false;
    c1_stop=true;
    UpdateCar_1Wheel(2);
    Car_1_Forward(position_car1);
    break;
case 'l':
    c1_forward=false;
    c1_backward=false;
    c1_stop=false;
    break;

case 'x':
    c2_forward=true;
    c2_backward=false;
    c2_stop=true;
    UpdateCar_2Wheel(2);
    Car_2_Forward(position_car2);
    break;

case 'y':
    c2_forward=false;
    c2_backward=true;
    c2_stop=true;
    UpdateCar_2Wheel(2);
    Car_2_Backward(position_car2);
    break;

case 'z':
    c2_forward=false;
    c2_backward=false;
    c2_stop=false;
    break;

case 'e':
    b_forward=true;
    b_backward=false;
    BoatForward(position_boat1);
    break;

case 'q':
    b_forward=false;
    b_backward=true;
    BoatBackward(position_boat2);
    break;

case 'r':
    b_forward=false;
    b_backward=false;
    break;
case 'h':
    rainday = true;
    Rain(_rain);
    break;
case 'j':
    rainday = false;
    Rain(_rain);
    break;
case 'n':
    glutDisplayFunc(Night);
    break;
case 'm':
    glutDisplayFunc(display);
    break;
   }
glutPostRedisplay();
}


void init()
{
    glClearColor(1.0,0.0,1.0,0.0);
	gluOrtho2D(0,1000,0,1000);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("project");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(25, UpdateCloud1, 0);
    glutTimerFunc(25, UpdateCloud2, 0);
    glutTimerFunc(25, UpdateCloud3, 0);
    glutTimerFunc(25, UpdateSun, 0);
    //glutTimerFunc(20, UpdateTrainWheelPosition, 0);

    glutMainLoop();
}
