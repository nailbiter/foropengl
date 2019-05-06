#include <cstdio>
#include <cstdlib>
#include <GLUT/glut.h>
#include <cmath>
#define deg_to_rad(deg) (((deg)/360)*2*M_PI)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

double angle = 0.0;
double step = 1.0;

void drawTriangle(){
    angle += step;
    while( angle >= 360.0 ) {
        angle -= 360.0;
    }

    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glBegin(GL_QUADS);
        glVertex2f(-0.7+std::cos(deg_to_rad(angle)),0.7);
        glVertex2f(-0.7+std::cos(deg_to_rad(angle)),-0.7);
        glVertex2f(0.7+std::cos(deg_to_rad(angle)),-0.7);
        glVertex2f(0.7+std::cos(deg_to_rad(angle)),0.7);
    glEnd();

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}
void keyEscape( unsigned char key, int x, int y ){
    switch ( key )
    {
        case 113: // 'Q' key for escape
            int windowID = glutCreateWindow ("triangle");
            glutDestroyWindow (windowID);
            exit(0);
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating a triangle");
    glutDisplayFunc(drawTriangle);
    glutKeyboardFunc(keyEscape);
    glutMainLoop();
    return 0;
}
