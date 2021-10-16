#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	int countPositive = 0,
		countNegative = -1,
		maxPositive = 0,
		minPositive = 1000,
		maxIndex = 0,
		minIndex = 0;
	float summ = 0.0,
		a = 0.0,
		numbersPositive = 0.0,
		numbersNegative = 0.0;
	std::cout << "Введите числа, с которыми хотите произвести операции.\n";
	std::cout << "Концом последовательности является число 0.\n";
	while (a != 0)
	{
		std::cin >> a;
		summ += a;
		if (a > 0)
		{
			numbersPositive += a;
			countPositive += 1;
			if (maxPositive < a)
			{
				maxPositive = a;
				maxIndex = countPositive;
			}
			if (minPositive > a)
			{
				minPositive = a;
				minIndex = countPositive;
			}
		}
		else
		{
			numbersNegative += a;
			countNegative += 1;
		}
	}
	if (!std::cin.good())
	{
		std::cerr << "Ошибка. Введено не число.\n";
		return 1;
	}
	std::cout << "Введите оператор, который хотите применить к набору чисел.\n";
	std::cout << "Сумма (+), Ср арифм всех(/), Ср арифм полож(|), Макс число и его номер(m)," << '\n' <<
		"Мин полож числ и его номер(k).\n";
	char operation = ' ';
	float result = 0.0;
	std::cin >> operation;
	switch (operation)
	{
	case '+':
		std::cout << summ;
		break;
	case '/':
		result = summ / static_cast<float>(countPositive + countNegative);
		std::cout << result;
		break;
	case '|':
		result = numbersPositive / static_cast<float>(countPositive);
		std::cout << result;
		break;
	case 'm':
		std::cout << maxPositive << ' ' << maxIndex;
		break;
	case 'k':
		std::cout << minPositive << ' ' << minIndex;
		break;
	}
	return 0;
}