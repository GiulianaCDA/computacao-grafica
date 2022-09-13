#include <iostream>
#include <GL/glut.h>


//using namespace std;


struct Color {
  GLfloat red;
  GLfloat green;
  GLfloat blue;
};
typedef struct Color color;

color PINK;
color BLUE;
color GREEN;
color ORANGE;
color cores[4];
int i = 0;
void init (void){
  /* selecionar cor de fundo (preto) */

  PINK.red = 0.24f;
  PINK.green = 0.79f;
  PINK.blue = 0.89f;

  BLUE.red = 1.0f;
  BLUE.green = 0.72f;
  BLUE.blue = 0.27f;

  GREEN.red = 0.6f;
  GREEN.green = 1.0f;
  GREEN.blue = 0.43f;

  ORANGE.red = 0.95f;
  ORANGE.green = 0.05f;
  ORANGE.blue = 0.5f;

  cores[0] = PINK;
  cores[1] = BLUE;
  cores[2] = GREEN;
  cores[3] = ORANGE;

  glClearColor (0.0, 0.0, 0.0, 0.0);

  glMatrixMode (GL_PROJECTION); //Projecao 2D

  glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0); //Definindo os limites da Porta de Visao (ViewPort)

}

void displayFcn(void){
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 1.0, .0);
   glBegin(GL_POLYGON);
   	 glVertex3f (249.0f, 250.0f, -1.0f);
       glVertex3f (251.0f, 250.0f, -1.0f);
       glVertex3f (249.0f, 100.0f, -1.0f);
       glVertex3f (251.0f, 100.0f, -1.0f);
   glEnd();

   glColor3f (cores[i].red, cores[i].green, cores[i].blue);
     glBegin(GL_TRIANGLES);
      glVertex2f (250.0f, 250.0f);
      glVertex2f (230.0f, 200.0f);
      glVertex2f (270.0f, 200.0f);
   glEnd();

   i++;
   i = i%4;

   glColor3f (cores[i].red, cores[i].green, cores[i].blue);
   glBegin(GL_TRIANGLES);
      glVertex2f (250.0f, 250.0f);
      glVertex2f (300.0f, 230.0f);
      glVertex2f (300.0f, 270.0f);
   glEnd();

   i++;
   i = i%4;

   glColor3f (cores[i].red, cores[i].green, cores[i].blue);
   glBegin(GL_TRIANGLES);
      glVertex2f (250.0f, 250.0f);
      glVertex2f (230.0f, 300.0f);
      glVertex2f (270.0f, 300.0f);
   glEnd();

   i++;
   i = i%4;

   glColor3f (cores[i].red, cores[i].green, cores[i].blue);
   glBegin(GL_TRIANGLES);
      glVertex2f (250.0f, 250.0f);
      glVertex2f (200.0f, 270.0f);
      glVertex2f (200.0f, 230.0f);
   glEnd();

   glFlush ();
}

void changeColor(unsigned char key, int x, int y) {

    if(key == 'Y' || key == 'y'){
        displayFcn();
    }   
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 400);
	glutInitWindowPosition (200, 200);
	glutCreateWindow ("Flor de Abril");

	init();

	glutDisplayFunc(displayFcn);
    glutKeyboardFunc(changeColor);
	glutMainLoop();

	
	return 0;

}

