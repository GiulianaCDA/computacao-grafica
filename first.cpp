#include <stdio.h>
#include <GL/glut.h>

 void Desenha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
        glVertex2i(100, 150);
        glVertex2i(100, 100);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(150, 100);
        glVertex2i(150, 150);
    glEnd();

    glFlush();
 }

 void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    if(h == 0) h = 1;

    glViewport(0, 0, w, h); //especifica dimensoes da viewport
    
    // inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // estabelece a janela de seleção (left, right, bottom, top)
    if(w <= h){
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h/w);
    }
    else{
        gluOrtho2D(0.0f, 250.0f*w/h, 0.0f, 250.0f);
    }

}

 void Inicializa(){
    glClearColor(0.0f, 0.8f, 0.8f, 1.0f);
 }
 int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Quadrado");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
    return 0;
 }