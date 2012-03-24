#include "GL/freeglut.h"
#include "GL/gl.h"
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

float WinWid = 400.0;
float WinHei = 400.0;

int Angel = 0.0;
float Scale = 1.0;

char ang[7+5] = "Angel: ";
char res[7+5] = "Angel: ";
char buf[5];

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    Angel%=360;
    //glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    Scale = 1.0 - fabs(sin(3.14*Angel/90.0)/sqrt(3.0)/2);
    glRotatef(Angel, 0.0, 0.0, 1.0);
    glScalef(Scale, Scale, 1.0);
    glBegin(GL_LINES);
    for(float i = -WinWid/2; i<= WinWid/2; i+=20.0) {
        glVertex2f(i, -WinHei/2);
        glVertex2f(i, WinHei/2);
    }
    for(float i = -WinHei/2; i<= WinHei/2; i+=20.0) {
        glVertex2f(-WinWid/2, i);
        glVertex2f(WinWid/2, i);
    }
    glEnd();
    strcpy(ang, res);
    sprintf(buf, "%d", Angel);
    strcat(ang, buf);
    glutSetWindowTitle(ang);
    glPopMatrix();
    glutSwapBuffers();
}

void Timer(int value) {
    /*
    switch(value) {
        case 0:
            glColor3f(1.0, 1.0, 1.0);
            break;
        case 1:
            glColor3f(1.0, 0.0, 0.0);
            break;
    }*/
    glColor3f(1.0, 1.0, 1.0);
    //Draw();
    glutPostRedisplay();
    glutTimerFunc(50, Timer, 0);
}

void Keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'a' :
            Angel++;
            break;
        case 'd' :
            Angel--;
            break;
    }
}

void SKeyboard(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT:
            Angel++;
            break;
        case GLUT_KEY_RIGHT:
            Angel--;
            break;
    }
}

void Initsialaize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Lesson 05");
    
    glutDisplayFunc(Draw);
    glutTimerFunc(50, Timer, 0);
    
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SKeyboard);
    
    Initsialaize();
    glutMainLoop();
    
    return 0;
}

