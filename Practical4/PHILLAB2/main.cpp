//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 




////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 
int main()
{
	// Create the main window 
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML OpenGL");

	// Create a clock for measuring time elapsed     
	sf::Clock Clock;

	//prepare OpenGL surface for HSR 
	glClearDepth(1.f);
	glClearColor(0.0f, 0.0f, 0.0f, 0.f); //background colour
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);

	//// Setup a perspective projection & Camera position 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //Load The Identity Matrix

	//set up a 3D Perspective View volume
	//glUPerspective(90.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar 

	//set up a  orthographic projection same size as window
	//this mease the vertex coordinates are in pixel space
	glOrtho(0, 800, 0, 600, 0, 1); // use pixel coordinates




								   // Start game loop 
	while (App.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (App.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				App.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				App.close();


		}

		//Prepare for drawing 
		// Clear color and depth buffer 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Apply some transformations 
		// https://www.opengl.org/sdk/docs/man2/xhtml/glMatrixMode.xml
		glMatrixMode(GL_MODELVIEW);
		// https://www.opengl.org/sdk/docs/man2/xhtml/glLoadIdentity.xml
		glLoadIdentity();

		double angle = Clock.getElapsedTime().asMilliseconds();
		glTranslated(+400, +300, 0); //shift to original position
		glRotatef(angle / 10, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.0f, 0.0f, 0.0f);
		glScalef(0.5f, 0.5f, 1.0f);
		glTranslated(-400, -300, 0);// shift centre to origin
		glTranslatef(1000.0f, 0.0f, 0.0f);
		glScalef(0.5f, 0.5f, 1.0f);

		//glEnd();
		for (int i = -1000; i < 100000; i += 400)
		{
			for (int j = -1000; j < 100000; j += 400)
			{
				glBegin(GL_QUADS);
				glColor3d(1, 1, 1);
				glVertex2d(i, j);
				glColor3d(0, 0, 1);
				glVertex2d(i + 400, j);
				glColor3d(0, 1, 0);
				glVertex2d(i + 400, j + 400);
				glColor3d(1, 0, 0);
				glVertex2d(i, j + 400);
				glEnd();
			}
		}

		// Finally, display rendered frame on screen 
		App.display();
	}

	return EXIT_SUCCESS;
}