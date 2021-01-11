#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

float p = -10.0,q = 0,a=-10.0;

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(p,3);
    glVertex2f(p+3,3);
    glVertex2f(p+3,-3);
    glVertex2f(p,-3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-3,a);
    glVertex2f(-3,a+3);
    glVertex2f(3,a+3);
    glVertex2f(3,a);
    glEnd();

    ///Horizontal
    if(p<=7 && q==0){
        p+=0.005;
    }else{
        //p=-10;
        q=1;
    }

    if(p>=-10 && q==1){
        p-=0.005;
    }else{
        //p=-10;
        q=0;
    }
    glutPostRedisplay();

    ///Vertical
    if(a<=7 && q==0){
        a+=0.005;
    }else{
        //p=-10;
        q=1;
    }

    if(a>=-10 && q==1){
        a-=0.005;
    }else{
        //p=-10;
        q=0;
    }
    glutPostRedisplay();

    glFlush();
}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glOrtho(-10,10,-10,10,-10,10);
}

int main(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("moving_object");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
