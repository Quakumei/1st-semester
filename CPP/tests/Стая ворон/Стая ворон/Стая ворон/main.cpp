#include <iostream>
#include <string>

std::string ending(int n)
{
	if (n%100 != 11 && n % 10 == 1) 
	{
		return "�";
	}
	else if (!(n % 100 >= 12 && n % 100 <= 14) 
		     && (n % 10 >= 2 && n % 10 <= 4))
	{
		return "�";
	}
	else
	{
		return "";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n = 0;
	double n_trap = 0.0; // N_trap - �������-������� ��� ����� ����� � ��������� ������.
	std::cout << "������� ����� �����: ";
	std::cin >> n_trap;
	n = static_cast<int>(n_trap);
	const int NATURAL_MIN = 1;

	if (!std::cin.good() || n_trap < NATURAL_MIN || n != n_trap) {
		std::cerr << "���� �����������, ���������� ���������";
		return 1;
	}

	std::cout << "� ���� " << n << " �����" << ending(n);
	return 0;
}