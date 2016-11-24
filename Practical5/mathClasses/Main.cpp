#include <iostream>
#include <string>
#include "Vector3.h"

int main()
{
	std::cout << "System Running" << std::endl;
	std::system("pause");
	Vector3 a(1, 2, 3);
	Vector3 b(a);
	std::cout << b.GetX() << std::endl << b.GetY() << std::endl << b.GetZ() << std::endl;
	std::system("pause");
	std::cout << b.ToString() << std:: endl;
	std::system("pause");
	std::cout << b.Length() << std::endl;
	std::system("pause");
	if (a.Equals(b))
	{
		std::cout << "equal" << std::endl;
	}
	else
	{
		std::cout << "not equal" << std::endl;
	}
	std::system("pause");
	Vector3 c = a - b;
	std::cout << c.ToString() << std::endl;
	std::system("pause");

	if (a == b)
	{
		std::cout << "Y" << std::endl;
	}
	else
	{
		std::cout << "X" << std::endl;
	}
	if (a == c)
	{
		std::cout << "X" << std::endl;
	}
	else
	{
		std::cout << "Y" << std::endl;
	}
	if (a != c)
	{
		std::cout << "Y" << std::endl;
	}
	else
	{
		std::cout << "X" << std::endl;
	}
	if (a != b)
	{
		std::cout << "X" << std::endl;
	}
	else
	{
		std::cout << "Y" << std::endl;
	}
	double e = 2;
	std::system("pause");
	std::cout << a.DotProduct(b) << std::endl;
	std::system("pause");
	std::cout << a.AngleBetween(b) << std::endl;
	std::system("pause");
	std::cout << acos(1);
	std::system("pause");
	Vector3 d = a.Scale(e);
	std::cout << d.ToString() << std::endl;
	std::system("pause");
}