#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<windows.h>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<mmsystem.h>

int delay = 1000 / 75;
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
double shiftXaxis = 0.0;
double shiftZaxis = 0.0;

double moveSpeed = 0.01;
double personMove = 0;

float shiftworldX = 0;
float shiftworldY = 0;
float shiftworldZ = 0;
float angle=0;


void reshapeFunc(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(0, -1, -1);
    glRotatef(-45, 1, 0, 0);
    gluPerspective(90.0, 2, 1, 30.0);
    glMatrixMode(GL_MODELVIEW);
}


void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(shiftworldX, shiftworldY, shiftworldZ);
    glPushMatrix();

    //ground
    glTranslatef(0.0, -1, 0.0);
    glColor3f(0.7, 0.3, 0.1);
    glScalef(40, 1, 40);
    glutSolidCube(0.6);
    glPopMatrix();

    //circle
    glPushMatrix();
    glColor3f(1.0,0,0.5);
    glTranslated(0 + shiftXaxis, 3, -10 + shiftZaxis);
    glutSolidSphere(2, 10, 10);
    glPopMatrix();

    //right circle
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(0.2+ shiftXaxis, 3, -10+ shiftZaxis);
    glutSolidSphere(0.08, 10, 10);
    glPopMatrix();
    //left circle
    glPushMatrix();
    glTranslated(-0.2 + shiftXaxis, 3, -10 + shiftZaxis);
    glutSolidSphere(0.08, 10, 10);
    glPopMatrix();

    //Rock
    glPushMatrix ();
    glColor3f(0.15,0.065,0);
    glTranslated(0, 0, 10);
    glRotatef(angle, 1, 1, 1);
    glutSolidCube(1) ;
    glPopMatrix ();

    //Trees
    glPushMatrix ();
    glColor3f(0,1,0);
    glScalef(1, 2, 1);
    glTranslated(5, 0.1, -7);
    glutSolidCube(1) ;
    glPopMatrix ();


    glPushMatrix ();
    glColor3f(0,1,0);
    glScalef(1, 6, 1);
    glTranslated(-5, 0.4, -4);
    glutSolidCube(1) ;
    glPopMatrix ();


    glPushMatrix ();
    glColor3f(0,1,0);
    glScalef(1, 4, 1);
    glTranslated(-5, 0.2, 5);
    glutSolidCube(1) ;
    glPopMatrix ();


   glPushMatrix ();
    glColor3f(0,1,0);
    glScalef(1, 2, 1);
    glTranslated(-5, 0.1, 11);
    glutSolidCube(1) ;
    glPopMatrix ();


    glPushMatrix ();
    glColor3f(0,1,0);
    glScalef(1, 2, 1);
    glTranslated(5, 0.1, -1);
    glutSolidCube(1) ;
    glPopMatrix ();


    glPushMatrix ();
    glColor3f(0,1,0);
    glScalef(1, 2, 1);
    glTranslated(5, 0.1, 8);
    glutSolidCube(1) ;
    glPopMatrix ();

    glutSwapBuffers();

}

void idleFunc(void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(delay, timer, 0);


    personMove += moveSpeed;
    if (personMove > 5 || personMove < -5) {
        moveSpeed = -moveSpeed;
    }
angle+=1;
  if(angle>360.0)
        angle=angle-360.0;


}

void screenmove(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
       shiftworldZ  ++;
        break;
    case 's':
        shiftworldZ --;
        break;
    case 'd':
        shiftworldX--;
        break;
    case 'a':
        shiftworldX++;
        break;
    case 'e':
        shiftworldY--;
        break;
    case 'q':
        shiftworldY++;
        break;
    }
}
float y=0;
void personmove(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:


        shiftXaxis --;

        break;
    case GLUT_KEY_RIGHT:
        shiftXaxis ++;
        break;
    case GLUT_KEY_UP:
        shiftZaxis--;
        break;

    case GLUT_KEY_DOWN:
        shiftZaxis++;
        break;
    }

}

int main(int argc, char** argv)
{
    //PlaySound(TEXT("20103360.wav")sync_none:SND);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("20103360");
    glClearColor(1.0, 1.0, 1.0, 0.0);


    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    glutKeyboardFunc(screenmove);
    glutSpecialFunc(personmove);
    glutIdleFunc(idleFunc);
    glutTimerFunc(0, timer, 0);
    glClearColor(1, 1, 0, 0.5);

    glutMainLoop();
}
