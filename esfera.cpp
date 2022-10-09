#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void init(void);
void display(void);
void reshape (int w, int h);
int SLICES = 30;
int STACKS = 30;
double SPHERE_RADIUS = 0.4;

void draw_sphere(){
    printf("entrou aqui");
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f); // yellow
    glutSolidSphere(SPHERE_RADIUS, SLICES, STACKS);
}

void init(void){
    // seta a cor do background para preto
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void reshape (int w, int h){
   int a = 0;
   printf("%d", a);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    draw_sphere();
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(556, 556);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Bola de futebol");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

