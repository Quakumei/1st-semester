#include <iostream>
#include <string>

std::string getTypeBySides(double a, double b, double c)
{
	if (a == b && b == c)
	{
		return "равносторонний";
	}
	else if (a == b || b == c) 
	{
		return "равнобедренный";
	}
	else
	{
		return "разносторонний";
	}
}

std::string getTypeByAngles(double a, double b, double c)
{
	const double PI = 3.14159265;
	double aAngle = acos((a*a+c*c-b*b)/(2*a*c))*180.0/PI, // в градусах
		   bAngle = acos((a*a+b*b-c*c)/(2*a*b))*180.0/PI, 
		   cAngle = acos((b*b+c*c-a*a)/(2*b*c))*180.0/PI;
	if (aAngle > 90 || bAngle > 90 || cAngle > 90)
	{
		return "тупоугольный";
	}
	if (aAngle == 90 || bAngle == 90 || cAngle == 90)
	{
		return "прямоугольный";
	}
	else 
	{
		return "остроугольный";
	}
}

int main() 
{
	setlocale(LC_ALL, "Russian");

	double a = 0.0, b = 0.0, c = 0.0;
	std::cout << "Введите стороны треугольника a b c:\n";
	std::cin >> a >> b >> c;

	if (!std::cin.good() || a < 0 || b < 0 || c < 0) {
		std::cerr << "Некорректный ввод, завершение программы";
		return 1;
	}
	if (!(a <= b + c) || !(b <= a + c) || !(c <= b + a))
	{
		std::cerr << "Стороны не образуют треугольника, завершение программы";
		return 1;
	}
	if ((a == b + c) || (b == a + c) || (c == a + b))
	{
		std::cout << "Треугольник является вырожденным, завершение программы"; // cout, тк не ошибка
		return 0;
	}

	std::string typeBySides = getTypeBySides(a, b, c);
	std::string typeByAngles = getTypeByAngles(a, b, c);

	std::cout << "Это " << typeBySides << " " << typeByAngles << " треугольник.";
	return 0;
}