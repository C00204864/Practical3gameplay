#include "Game.h"

//gAME cONSTRUCTOR
Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

//Game Destructor
Game::~Game(){}

//Game Run Method for Updating And Drawing
void Game::run()
{
	initialize();
	Event event;
	while (isRunning){
		cout << "Game running..." << endl;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}
}

//Initialize Method
void Game::initialize()
{
	isRunning = true;
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

//Update Method(remains empty)
void Game::update()
{
	cout << "Update up" << endl;
}

//Draw Method
void Game::draw()
{
	/*
	Note: the colours I use are entirely random
	*/
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

	//Implementation of GL_TRIANGLES
	glBegin(GL_TRIANGLES); //glBegin used to declare what the next primitive to be drawn is
	{ //Braces used to group together vertices and colours
		glColor3d(1, 1, 0); //Colour used above a vertex to determine what the vertex colour will be
		glVertex3f(1, 1.4, -5.0); //First Vertex
		glColor3d(0, 1, 1);
		glVertex3f(1.25, 1.9, -5.0);
		glColor3d(1, 0, 1);
		glVertex3f(1.5, 1.4, -5.0);
	}
	glEnd();

	//Implementation of GL_LINES
	glBegin(GL_LINES);
	{
		glColor3d(1, 0.5, 0);
		glVertex3f(1.5, 2.0, -5.0);
		glColor3d(0, 0.5, 1);
		glVertex3f(1, 2.0, -5.0);
	}
	glEnd();

	//Implementation of GL_LINE_STRIP
	glBegin(GL_LINE_STRIP);
	{
		glColor3d(1, 1, 0);
		glVertex3f(1, 1, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(1.5, 1, -5.0);
		glColor3d(1, 1, 1);
		glVertex3f(1, 0.75, -5.0);
		glColor3d(1, 0, 1);
		glVertex3f(1.5, 0.75, -5.0);
	}
	glEnd();

	////Implementation of GL_LINE_LOOP
	glBegin(GL_LINE_LOOP);
	{
		glColor3d(1, 1, 0);
		glVertex3f(1, 0.5, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(1.5, 0.5, -5.0);
		glColor3d(1, 1, 1);
		glVertex3f(1, 0.25, -5.0);
		glColor3d(1, 0, 1);
		glVertex3f(1.5, 0.25, -5.0);
	}
	glEnd();

	//Implementation of GL_TRIANGLE_STRIP
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3d(1, 1, 0);
		glVertex3f(1, 0, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(1, -0.25, -5.0);
		glColor3d(1, 1, 1);
		glVertex3f(1.25, -0.125, -5.0);
		glColor3d(1, 0, 1);
		glVertex3f(1.5, 0, -5.0);
		glColor3d(1, 1, 0);
		glVertex3f(1.5, -0.25, -5.0);
	}
	glEnd();

	//Implementation of GL_TRIANGLE_FAN
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3d(1, 1, 0);
		glVertex3f(-0.4, 0.2, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(0.5, 0.7, -5.0);
		glColor3d(1, 1, 1);
		glVertex3f(0.1, 0.9, -5.0);
		glColor3d(1, 0, 1);
		glVertex3f(0.7, 0.5, -5.0);
		glColor3d(1, 1, 0);
		glVertex3f(0.6, 0.4, -5.0);
	}
	glEnd();

	//Implementation of GL_QUADS
	glBegin(GL_QUADS);
	{
		glColor3d(1, 0, 1);
		glVertex3f(-2, 0, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(-1, 0, -5.0);
		glColor3d(1, 1, 1);
		glVertex3f(-1, -2, -5.0);
		glColor3d(1, 1, 0);
		glVertex3f(-2, -2, -5.0);
	}
	glEnd();

	//Implementation of GL_QUAD_STRIP
	glBegin(GL_QUAD_STRIP);
	{
		glColor3d(1, 0, 1);
		glVertex3f(-2, 2.5, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(-1, 2.5, -5.0);
		glColor3d(1, 1, 1);
		glVertex3f(-2, 0.5, -5.0);
		glColor3d(1, 1, 0);
		glVertex3f(-1, 0.5, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(-2.05, 0.4, -5.0);
		glColor3d(1, 0, 1);
		glVertex3f(-0.6, 0.4, -5.0);
	}
	glEnd();

	//Implementation of GL_POLYGON
	glBegin(GL_POLYGON);
	{
		glColor3d(1, 0, 1);
		glVertex3f(0, -1, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(1, -0.5, -5.0);
		glColor3d(1, 1, 0);
		glVertex3f(2, -1, -5.0);
		glColor3d(0, 1, 1);
		glVertex3f(1, -2, -5.0);
		glColor3d(0, 1, 0);
		glVertex3f(0, -2, -5.0);
	}
	glEnd();

	//Draw All Function
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

