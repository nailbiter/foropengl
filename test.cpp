#include <cstdio>
#include <cstdlib>
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

void drawTriangle(){
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glBegin(GL_TRIANGLES);
    glVertex3f(-0.7, 0.7, 0);
    glVertex3f(0.7, 0.7, 0);
    glVertex3f(0, -1, 0);
    glEnd();

    glFlush();
}
void keyEscape( unsigned char key, int x, int y )
{
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
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating a triangle");
    glutDisplayFunc(drawTriangle);
    glutKeyboardFunc(keyEscape);
    glutMainLoop();
    return 0;
}
