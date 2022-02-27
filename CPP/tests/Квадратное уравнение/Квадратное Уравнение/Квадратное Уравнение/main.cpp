#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	double a = 0.0, b = 0.0, c = 0.0;
	std::cout << "ax^2 + bx + c = 0\nВведите коэффициенты квадратного уравнения a b c (через пробел):\n";
	std::cin >> a >> b >> c;

	if (!std::cin.good())
	{
		std::cerr << "Коэффициенты квадратного уравнения должны быть числами, завершение программы";
		return 1;
	}
	
	if (a == 0.0)
	{
		std::cerr << "Ввод некорректен, уравнение не квадратное, завершение программы";
		return 1;
	}

	double D = b * b - 4 * a * c; //Дискриминант
	if (D < 0) 
	{
		std::cout << "Решений нет.";
	}
	else if (D == 0) 
	{
		double x = -b / (2 * a);
		std::cout << "Одно решение, x = " << x;
	}
	else // D > 0 
	{
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		std::cout << "Два решения, x = { " << x1 << ", " << x2 << " }";
	}

	return 0;
}