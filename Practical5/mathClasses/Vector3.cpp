#include "Vector3.h"

//Constructor Function
Vector3::Vector3(float xIn, float yIn, float zIn)
{
	m_x = xIn;
	m_y = yIn;
	m_z = zIn;
}

Vector3::Vector3(Vector3 &vIn)
{
	m_x = vIn.GetX();
	m_y = vIn.GetY();
	m_z = vIn.GetZ();
}

//Function To Read The Value Of The Private Member X
float Vector3::GetX() const
{
	return m_x;
}

//Function To Read The Value Of The Private Member Y
float Vector3::GetY() const
{
	return m_y;
}

//Function To Read The Value Of The Private Member Z
float Vector3::GetZ() const
{
	return m_z;
}

//Function Converts To String
std::string Vector3::ToString() const
{
	std::ostringstream ss;
	ss << m_x << ", " << m_y << ", " << m_z;
	return std::string(ss.str());
}

//Function Returns The Length Of The Vector
double Vector3::Length() const
{
	return (sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z)));
}

//Function Returns The Length Of The Vector Squared
double Vector3::LengthSquared() const
{
	return ((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

//Function To Tell if Two Vectors Are Equal
bool Vector3::Equals(Vector3 &vIn) const
{
	if (m_x == vIn.GetX() && m_y == vIn.GetY() && m_z == vIn.GetZ())
	{
		return true;
	}
	return false;
}

//'==' Operator Overload
bool Vector3::operator==(Vector3 &vIn) const
{
	if (m_x == vIn.GetX() && m_y == vIn.GetY() && m_z == vIn.GetZ())
	{
		return true;
	}
	return false;
}

//'!=' Operator Overload
bool Vector3::operator!=(Vector3 &vIn) const
{
	if (m_x != vIn.GetX() || m_y != vIn.GetY() || m_z != vIn.GetZ())
	{
		return true;
	}
	return false;
}

//'+' Operator Overload
Vector3 Vector3::operator+(Vector3 &vIn) const
{
	return Vector3((m_x + vIn.GetX()), (m_y + vIn.GetY()), (m_z + vIn.GetZ()));
}

//'-' Operator Overload
Vector3 Vector3::operator-(Vector3 &vIn) const
{
	return Vector3((m_x - vIn.GetX()), (m_y - vIn.GetY()), (m_z - vIn.GetZ()));
}

//Function Calculates And Returns The Dot Product Of Two Vectors
double Vector3::DotProduct(Vector3 &vIn) const
{
	return double((m_x * vIn.GetX()) + (m_y * vIn.GetY()) + (m_z * vIn.GetZ()));
}

//Function Calculates And Returns The Cross Product OF Two Vectors
Vector3 Vector3::CrossProduct(Vector3 &vIn) const
{
	return Vector3(((m_y * vIn.GetZ()) - (m_z * vIn.GetY())), ((m_x * vIn.GetZ()) - (m_z * vIn.GetX())), ((m_x * vIn.GetY()) - (m_y * vIn.GetX()))); //Done Using The Determinant Method
}

//Function Calculates the Angle Between Two Vectors (slightly off due to the inaccuracy of acos)
double Vector3::AngleBetween(Vector3 &vIn) const
{
	Vector3 v(m_x, m_y, m_z);
	return (180 / std::acos(-1)) * (std::acos(v.DotProduct(vIn) / (v.Length() * vIn.Length())));
}

//Function That Returns A Unit Vector
Vector3 Vector3::Unit()
{
	Vector3 tempVector(m_x, m_y, m_z);
	double length = tempVector.Length();
	return Vector3(m_x / length, m_y / length, m_z / length);
}

//Function Calculates The Parallel Component Of A Vector (Parallel To Parameter)
Vector3 Vector3::ParallelComponent(Vector3 &vIn)
{
	Vector3 v1(vIn);
	Vector3 v2(m_x, m_y, m_z);
	double lengthSqrd = v1.LengthSquared();
	double dotProduct = v1.DotProduct(v2);
	double multiplier = dotProduct / lengthSqrd;
	return Vector3(m_x * multiplier, m_y * multiplier, m_z * multiplier);
}

//Function Calculates The Perpendicular Component Of A Vector (Perpendicularl To Parameter)
Vector3 Vector3::PerpendicularComponent(Vector3 &vIn)
{
	Vector3 v1(vIn);
	Vector3 v2(m_x, m_y, m_z);
	return (v2 - v1.ParallelComponent(v2));
}

//Returns A Scaled Vectoir (By Parameter)
Vector3 Vector3::Scale(float fIn)
{
	return Vector3(m_x * fIn, m_y * fIn, m_z * fIn);
}

//Overloaded - Returns A Scaled Vectoir (By Parameter)
Vector3 Vector3::Scale(double dIn)
{
	return Scale((float)(dIn));
}
