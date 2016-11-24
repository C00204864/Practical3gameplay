#pragma once
//#include <string>
//#include <sstream>
#include "Vector3.h"

/*
Liam Hickey
C00204864
Vector Class
*/

class Matrix3 {
public:
	//Constructor Functions
	Matrix3();
	Matrix3(Vector3 vOne, Vector3 vTwo, Vector3 vThree);
	Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33);

	//Getter Functions
	float GetM11() const;
	float GetM12() const;
	float GetM13() const;
	float GetM21() const;
	float GetM22() const;
	float GetM23() const;
	float GetM31() const;
	float GetM32() const;
	float GetM33() const;

	//Row And Column Functions
	Vector3 GetRow(int i) const;
	Vector3 GetCol(int i) const;

	//Operator Overloads
	Vector3 operator*(Vector3 & vIn) const;
	Matrix3 operator+(Matrix3 & mIn) const;
	Matrix3 operator-(Matrix3 & mIn) const;
	Matrix3 operator*(Matrix3 & mIn) const;
	Matrix3 operator*(float valIn)const;

	//Matrix Operation Functions
	Matrix3 Transpose();
	float Determinant();
	Matrix3 Inverse();

	//Rotational Functions
	Vector3 RotateAboutX(Vector3 vectorToRotate, float angle);
	Vector3 RotateAboutY(Vector3 vectorToRotate, float angle);
	Vector3 RotateAboutZ(Vector3 vectorToRotate, float angle);

private:
	//Component Cells Of The Matrix
	float m_11;
	float m_12;
	float m_13;
	float m_21;
	float m_22;
	float m_23;
	float m_31;
	float m_32;
	float m_33;
};