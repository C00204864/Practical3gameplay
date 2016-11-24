#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Matrix3.h"
#include "Quaternion.h"
#include "Vector3.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	Matrix3 mat = Matrix3(1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f);
	MyVector3 vec1 = MyVector3(-1.f, -1.f, -5.f);
	MyVector3 vec2 = MyVector3(0.f, 0.f, -5.f);
	MyVector3 vec3 = MyVector3(1.f, -1.f, -5.f);
	void unload();
};