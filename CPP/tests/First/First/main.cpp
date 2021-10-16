#include <iostream>

double convert(double inch)
{
	const double INCH_TO_CM = 2.54;
	return inch * INCH_TO_CM;
}

int main() 
{
	double inch = 0.0;
	std::cout << "inches: ";
	std::cin >> inch;
	double cm = convert(inch);
	std::cout << inch << " in = " 
		<< cm << " cm\n";
	return 0;
}