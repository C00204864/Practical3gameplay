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
	Matrix3 m = Matrix3(1.001, 0, 0 , 0, 1.001, 0, 0, 0, 1);
	Matrix3 translate = Matrix3(1, 0, 0.001, 0, 1, 0.001, 0, 0, 1);
	Matrix3 antiM = Matrix3(1/1.001, 0, 0, 0, 1/1.001, 0, 0, 0, 1);
	Matrix3 antiTranslate = Matrix3(1, 0, -0.001, 0, 1, -0.001, 0, 0, 1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		vec1 = m.RotateAboutZ(vec1, 1);
		vec2 = m.RotateAboutZ(vec2, 1);
		vec3 = m.RotateAboutZ(vec3, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		vec1 = m * vec1;
		vec2 = m * vec2;
		vec3 = m * vec3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		vec1 = translate * vec1;
		vec2 = translate * vec2;
		vec3 = translate * vec3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		vec1 = antiM * vec1;
		vec2 = antiM * vec2;
		vec3 = antiM * vec3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		vec1 = antiTranslate * vec1;
		vec2 = antiTranslate * vec2;
		vec3 = antiTranslate * vec3;
	}
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
		glVertex3f(vec1.GetX(), vec1.GetY(), vec1.GetZ()); //First Vertex
		glColor3d(0, 1, 1);
		glVertex3f(vec2.GetX(), vec2.GetY(), vec2.GetZ());
		glColor3d(1, 0, 1);
		glVertex3f(vec3.GetX(), vec3.GetY(), vec3.GetZ());
	}
	glEnd();

	//Draw All Function
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

