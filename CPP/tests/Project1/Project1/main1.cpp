#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;
	if (!std::cin)
	{
		std::cerr << "���� �����������, ���������� ���������";
		return 1;
	}
	int nEven = a % 2 + b % 2 + c % 2;
	std::cout << ((nEven != 0 && nEven != 3) ? "��" : "���");
	return 0;
}