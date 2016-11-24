#include "Quaternion.h"

//Constructor Function
Quaternion::Quaternion(float wIn, float xIn, float yIn, float zIn) : m_w(wIn), m_x(xIn), m_y(yIn), m_z(zIn) {}

//Function Returns The W Component Of The Quaternion
float Quaternion::GetW()
{
	return m_w;
}

//Function Returns The X Component Of The Quaternion
float Quaternion::GetX()
{
	return m_x;
}

//Function Returns The Y Component Of The Quaternion
float Quaternion::GetY()
{
	return m_y;
}

//Function Returns The Z Component Of The Quaternion
float Quaternion::GetZ()
{
	return m_z;
}

//Function Converts The Quaternion To A String And Returns The String
std::string Quaternion::ToString()
{
	std::ostringstream ss;
	ss << m_w << ", " << m_x << ", " << m_y << ", " << m_z;
	return std::string(ss.str());
}

//'+' Operator Overload
Quaternion Quaternion::operator+(Quaternion q2)
{
	return Quaternion((m_w + q2.GetW()), (m_x + q2.GetX()), (m_y + q2.GetY()), (m_z + q2.GetZ()));
}

//'-' Operator Overload
Quaternion Quaternion::operator-(Quaternion q2)
{
	return Quaternion((m_w - q2.GetW()), (m_x - q2.GetX()), (m_y - q2.GetY()), (m_z - q2.GetZ()));
}

//'*' Operator Overload
Quaternion Quaternion::operator*(Quaternion q2)
{
	return Quaternion(
		(m_w * q2.GetW()) - (m_x * q2.GetX()) - (m_y * q2.GetY()) - (m_z * q2.GetZ()),
		(m_w * q2.GetX()) + (m_x * q2.GetW()) + (m_y * q2.GetZ()) - (m_z * q2.GetY()),
		(m_w * q2.GetY()) + (m_y * q2.GetW()) + (m_z * q2.GetX()) - (m_x * q2.GetZ()),
		(m_w * q2.GetZ()) + (m_z * q2.GetW()) + (m_x * q2.GetY()) - (m_y * q2.GetX())
	);
}

//Function Calculates And Returns The Modulus Of A Quaternion
float Quaternion::Modulus()
{
	return (float)(sqrt((m_w * m_w) + (m_x * m_x) + (m_y * m_y) + (m_z * m_z)));
}

//Function Normalises And Returns A Quaternion
Quaternion Quaternion::Normalise()
{
	float modulus = this->Modulus();
	if (modulus != 1)
	{
		return Quaternion(m_w / modulus, m_x / modulus, m_y / modulus, m_z / modulus);
	}
	return *this;
}

//Function Returns The Negated Form Of The Quaternion
Quaternion Quaternion::Negate()
{
	return Quaternion(-m_w, -m_x, -m_y, -m_z);
}

//Function Returns The Conjugate Of The Quaternion
Quaternion Quaternion::Conjugate()
{
	return Quaternion(m_w, -m_x, -m_y, -m_z);
}

//Function Scales The Quaternion By A Value Passed As A Parameter
Quaternion Quaternion::Scale(float scaleValue)
{
	return Quaternion(m_w * scaleValue, m_x * scaleValue, m_y * scaleValue, m_z * scaleValue);
}

//Function Calculates And Returns The Inverse Of A Quaternion
Quaternion Quaternion::Inverse()
{
	Quaternion q1 = this->Conjugate();
	float multiplier = q1.Modulus();
	multiplier = (1.f / (multiplier * multiplier));
	q1 = q1.Scale(multiplier);
	return q1;
}

//Function Rotates A Vector About A Quaternion By A Given Angle
Vector3 Quaternion::Rotate(Vector3 vectorToRotate, float angle)
{
	angle = (angle / 180.f) * acos(-1);
	float cosValue = (float)cos(angle / 2.f);
	float sinValue = (float)sin(angle / 2.f);
	Quaternion q1 = this->Normalise();
	Quaternion rotational = Quaternion(cosValue, (sinValue * q1.GetX()), (sinValue * q1.GetY()), (sinValue * q1.GetY()));
	Quaternion conjugate = rotational.Conjugate();
	Quaternion point = (0, vectorToRotate.GetX(), vectorToRotate.GetY(), vectorToRotate.GetZ());
	q1 = (rotational * point) * conjugate;
	return Vector3(q1.GetX(), q1.GetY(), q1.GetZ());
}

//Function Rotates A Vector About The X Axis By A Given Value
Vector3 Quaternion::RotateAboutX(Vector3 vectorToRotate, float angle)
{
	Quaternion rotationalQuaternion(0, 1, 0, 0);
	return rotationalQuaternion.Rotate(vectorToRotate, angle);
}

//Function Rotates A Vector About The Y Axis By A Given Value
Vector3 Quaternion::RotateAboutY(Vector3 vectorToRotate, float angle)
{
	Quaternion rotationalQuaternion(0, 0, 1, 0);
	return rotationalQuaternion.Rotate(vectorToRotate, angle);
}

//Function Rotates A Vector About The Z Axis By A Given Value
Vector3 Quaternion::RotateAboutZ(Vector3 vectorToRotate, float angle)
{
	Quaternion rotationalQuaternion(0, 0, 0, 1);
	return rotationalQuaternion.Rotate(vectorToRotate, angle);
}