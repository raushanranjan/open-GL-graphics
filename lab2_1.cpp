#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
void displayText( ) 
{
	const char *str=" Haunted Hut";
	int j = strlen( str );
	glColor3f( 1, 1, 1 );
	glRasterPos2f( -50, -350 );
	for( int i = 0; i < j; i++ ) 
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str[i] );
	}

	const char *str2="Raushan Ranjan R124214051";
	j = strlen( str2 );
	glColor3f( 1, 1, 0 );
	glRasterPos2f( -350, 450 );
	for( int i = 0; i < j; i++ ) 
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str2[i] );
	}
}
void display(void);
	
	
void DrawCircle(float cx, float cy, float r, int num_segments)
    {
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);

    }
    glEnd();
    glFlush();
    }
	void Rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
glBegin(GL_POLYGON);
		glVertex2f(x1,y1);//K
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		glEnd();	
}

void myMouseFunc(int button, int state, int x, int y)
{
    float xw= float((x*500)/350) -500;
    float yw= 500 -float((y*500)/350);
     /*printf("%f\t", xw);
     printf("%f\n", yw);*/
     float x1= -300, y1= 200, r=50;
     float x2= 300;
     float k= ((xw-x1)*(xw-x1))+((yw-y1)*(yw-y1)) -(r*r);
     float k2= ((xw-x2)*(xw-x2))+((yw-y1)*(yw-y1)) -(r*r);
	
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && k<=0 ) {
		 
        glColor3f(1.0, 0, 0.0);
		DrawCircle(x2,y1, r, 360); 
		
        
	}
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && k<=0) 
    {
		 glColor3f(1.0, 1.0, 1.0);
       DrawCircle(x2, y1, r, 360);
	   
       
	}


	else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && k2<=0) 
    {
		 glColor3f(1.0, 1.0, 1.0);
       DrawCircle(x1, y1, r, 360);
	   
       
	}
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && k2<=0) 
    {
		 glColor3f(1.0, 0, 0);
       DrawCircle(x1, y1, r, 360);
	   
       
	}
}

	void display()
	{

		glClearColor(0,0,0,1);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
		glColor3f(1,1,0);
		glVertex2f(-400,200);//K
		glVertex2f(-400,-200);//A
		glVertex2f(400,-200);//B
		glVertex2f(400,200);//c
		glVertex2f(300,300);//D
		glVertex2f(200,200);//E
		glVertex2f(100,200);//F
		glVertex2f(0,300);//G
		glVertex2f(-100,200);//H
		glVertex2f(-200,200);//I
		glVertex2f(-300,300);//J
		glEnd();
		glColor3f(0,1,0);
		Rectangle(0,300, 100,200, 200, 200, 300, 300);
		Rectangle(0,300, -100,200, -200, 200, -300, 300);

		glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex2f(-150,0);
		glVertex2f(150,0);
		glVertex2f(150,0);
		glVertex2f(150,200);
		glVertex2f(-150,0);
		glVertex2f(-150,200);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex2f(-100,100);
		glVertex2f(100,100);
		glVertex2f(-100,100);
		glVertex2f(-100,0);
		glVertex2f(100,100);
		glVertex2f(100,0);
		glEnd();
		glColor3f(1,1,1);
		Rectangle(-100, 100, 100, 100, 100, 0, -100, 0);
		glBegin(GL_LINES);
		glColor3f(0,0,0);
		float x = -100;
		float y = -80;
		while (x <= 80 && y <= 100){
			glVertex2f(x, 100);
			glVertex2f(y, 0);
			x = x + 20;
			y = y + 20;
		} 
 		glEnd();
		glColor3f(0,1,0);
		Rectangle(-400, 100, -400, -100, -350, -100, -350, 100);
		Rectangle(400, 100, 400, -100, 350, -100, 350, 100);
		glColor3f(0,1,1);
        Rectangle(300, -200, 250, -200, 250, -50, 300, -50);
		Rectangle(-300, -200, -250, -200, -250, -50, -300, -50);
		
		
		glColor3f(1.0, 0, 0);
        
        DrawCircle(-300, 200, 50, 360);
        glColor3f(1.0, 1.0, 1.0);
		DrawCircle(300,200, 50, 360);
        displayText( );
		glFlush();

	}
    int main(int argc,char** argv)
	{
	
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowPosition(50,50);
		glutInitWindowSize(700,700);
		glutCreateWindow("hut");	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-500,500,-500,500);		
		glutDisplayFunc(display);
		glutMouseFunc(myMouseFunc);
		glutMainLoop();
		return 0;
	
	}