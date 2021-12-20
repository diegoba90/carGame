#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#define MSEC_PER_FRAME 10

float xPos = 0, yPos = 0, zPos = 0;
//truck values
float carFront[] = {xPos, yPos, zPos};
float carFrontSizeX = 2;
float carFrontSizeY = 1;
float carFrontSizeZ = 1;
float carBack[] = {xPos, yPos, zPos};
//object values
float obj[] = {xPos, yPos, zPos};
float objSizeX = 1;
float objSizeY = 1;
float objSizeZ = 1;
//game values
bool pauseGame = false;
bool collision = false;
int score = 0;



//function for text display
void writeBitmapString(void *font, char *string)
{
	for (char* c = string; *c != '\0'; c++)
		glutBitmapCharacter(font, *c);
}

//function to draw the track
void drawTrack(){
    //track
	glColor3f(.5, .5, .5);
	glBegin(GL_POLYGON);
	glVertex3f(xPos + 8, yPos, -4000);
	glVertex3f(xPos - 8, yPos, -4000);
	glVertex3f(xPos - 8, yPos, 20);
	glVertex3f(xPos + 8, yPos, 20);
	glEnd();

    //center divider
	glColor3f(1, 1, 1);
	for (int i = -4000; i <= 4000; i += 10)
	{
		glBegin(GL_POLYGON);
		glVertex3f(xPos - 0.1, yPos, i);
		glVertex3f(xPos + 0.1, yPos, i);
		glVertex3f(xPos + 0.1, yPos, i + 5);
		glVertex3f(xPos - 0.1, yPos, i + 5);
		glEnd();
	} 

    //grass area
	glColor3f(0, 1.0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1000, -0.14, -4000);
	glVertex3f(1000, -0.14, -4000);
	glVertex3f(1000, -0.14, 4000);
	glVertex3f(-1000, -0.14, 4000);
	glEnd();

    glFlush();
}
//draw the truck

void drawTruck(){

    //front of truck
    glPushMatrix();
		glTranslatef(carFront[0] + 4, carFront[1] + 1, carFront[2] + 2);
        glScalef(carFrontSizeX, carFrontSizeY, carFrontSizeZ);
		glColor3f(0,0,0);
        glutWireCube(1.5);
		glColor3f(1,0,1);
        glutSolidCube(1.5);
	glPopMatrix();
    //back of truck
    glPushMatrix();
		glTranslatef(carBack[0] + 4, carBack[1] + 1, carBack[2] + 4);
		glColor3f(0,0,0);
        glutWireCube(3);
		glColor3f(1,0,1);
        glutSolidCube(3);
	glPopMatrix();

} 

void drawRandomObjects(){

	glPushMatrix();
		glScalef(objSizeX, objSizeY, objSizeZ); //size of object
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 100);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 130);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 160);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 190);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 220);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 250);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 280);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 310);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 340);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 370);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 400);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 430);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 460);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 490);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 520);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 550);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 580);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 610);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//left object
		glPushMatrix();
			glTranslatef(obj[0] - 4, obj[1] + 1, obj[2] - 640);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
		//right object
        glPushMatrix();
			glTranslatef(obj[0] + 4, obj[1] + 1, obj[2] - 670);
			glColor3f(0,0,0); glutWireCube(2);
			glColor3f(0,1,0); glutSolidCube(2);
		glPopMatrix();
	glPopMatrix();

	glutPostRedisplay();

}

bool checkCollision(){

	//it's checking to see if objects are touching obj[0] + 4, obj[1] + 1, obj[2] - 130
	if(obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 100 == carFront[2] + 2){
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 130 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 160 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 190 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 220 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 250 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 280 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 310 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 340 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 370 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 400 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 430 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 460 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 490 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 520 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 550 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 580 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 610 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] + 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 640 == carFront[2] + 2) {
		return true;
	} else if (obj[0] - 4 == carFront[0] - 4 && obj[1] + 1 == carFront[1] + 1 && obj[2] - 670 == carFront[2] + 2) {
		return true;
	} else {
		false;
	}
}

void drawMessage(char* msg){

	glLoadIdentity();
	glColor3f(0,0,0);
	glRasterPos3f(xPos -10, yPos + 20, -35);
	writeBitmapString(GLUT_BITMAP_HELVETICA_18, msg);
}

void printScore()
{
	char buffer[50];
    sprintf(buffer, "SCORE: %d", score);
    glColor3f(0, 0, 0);
	glRasterPos3f(xPos -50, yPos + 30, carFront[2]-35);
    writeBitmapString(GLUT_BITMAP_HELVETICA_18, buffer);
}


//Timer function is called in every MSEC_PER_FRAME milliseconds
void timerFunc(int value){

	//truck moves forward
	if(!pauseGame){
		carFront[2]--;
		carBack[2]--;
		collision = checkCollision();
	}
	//Increase score when there is no collision
	if(!collision){
		score++;
	} else {
		pauseGame = true;
	}

	glutPostRedisplay();
	glutTimerFunc (MSEC_PER_FRAME, timerFunc, value);
}


void drawScene(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	//centered camera angle
	gluLookAt(xPos - 0.1, 8, carFront[2] + 8, xPos - 0.1, carFront[1], carFront[2] - 10, 0, 1, 0);

    glColor3f(1.0, 1.0, 1.0);
    drawTrack();

	//draw random objects
    drawRandomObjects();

    //draw truck
	drawTruck();

	//draw score
	printScore();

	//draw messsage
	if(collision){
		drawMessage("YOU LOSE!");
	}

    glutSwapBuffers(); //swap buffers

	glDisable(GL_DEPTH_TEST);
	glFlush();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:
			exit(0);
			break;
        case 'a':
            carFront[0] -= 8;
			carBack[0] -= 8;
            break;
        case 'd':
			carFront[0] += 8;
			carBack[0] += 8;           
            break;
		case ' ':
			if(pauseGame) pauseGame = false;
			else pauseGame = true;
			break;

        default:
            break;
		
	}
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120, w / h, 0.1, 100.0); //(angle of sight, width, height, depth)

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Main routine.
int main(int argc, char **argv){
	srand(time(0));
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("ACUNA_D_HW4");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glutTimerFunc(MSEC_PER_FRAME, timerFunc, 1);


	setup();

	glutMainLoop();
}







// g++ -framework OpenGL -lGLUT -I /opt/X11/include -L /opt/X11/lib -w -o out game.cpp
