#include <iostream>
#include <iomanip>

int main2()
{
	int i = 0;
	float test = 0;
	while (test == static_cast<float>(i))
	{
		++i;
		test += 1.0;
	}
	std::cout << std::setprecision(25);
	std::cout << i << ", " << test;
	return 0;
}