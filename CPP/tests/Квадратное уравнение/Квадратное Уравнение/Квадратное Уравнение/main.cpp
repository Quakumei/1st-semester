#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	double a = 0.0, b = 0.0, c = 0.0;
	std::cout << "ax^2 + bx + c = 0\n������� ������������ ����������� ��������� a b c (����� ������):\n";
	std::cin >> a >> b >> c;

	if (!std::cin.good())
	{
		std::cerr << "������������ ����������� ��������� ������ ���� �������, ���������� ���������";
		return 1;
	}
	
	if (a == 0.0)
	{
		std::cerr << "���� �����������, ��������� �� ����������, ���������� ���������";
		return 1;
	}

	double D = b * b - 4 * a * c; //������������
	if (D < 0) 
	{
		std::cout << "������� ���.";
	}
	else if (D == 0) 
	{
		double x = -b / (2 * a);
		std::cout << "���� �������, x = " << x;
	}
	else // D > 0 
	{
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		std::cout << "��� �������, x = { " << x1 << ", " << x2 << " }";
	}

	return 0;
}