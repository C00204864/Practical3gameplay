#pragma once
#include <string>
#include <sstream>

/*
Liam Hickey
C00204864
Vector Class
*/

class Vector3 {
public:
	//Constructor Functions
	Vector3(float xIn = 0.f, float yIn = 0.f, float zIn = 0.f);
	Vector3(Vector3 &vIn);

	//Getter Functions
	float GetX() const;
	float GetY() const;
	float GetZ() const;

	//To String Function
	std::string ToString() const;

	//Vector Length(Magnitude) Function
	double Length() const;
	double LengthSquared() const;

	//Determine If Two Vectors Are Equal Function
	bool Equals(Vector3 &vIn) const;

	//Vector Product Functions
	double DotProduct(Vector3 &vIn) const;
	Vector3 CrossProduct(Vector3 & vIn) const;

	//Operator Overloads
	bool operator==(Vector3 &vIn) const;
	bool operator!=(Vector3 &vIn) const;
	Vector3 operator+(Vector3 &vIn) const;
	Vector3 operator-(Vector3 &vIn) const;

	//Angle Between Two Vectors Function
	double AngleBetween(Vector3 & vIn) const;

	//Unit Vector Function
	Vector3 Unit();

	//Component Functions
	Vector3 ParallelComponent(Vector3 &vIn);
	Vector3 PerpendicularComponent(Vector3 &vIn);

	//Scale Functions
	Vector3 Scale(float fIn);
	Vector3 Scale(double dIn);

private:
	float m_x;
	float m_y;
	float m_z;

};