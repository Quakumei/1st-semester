#include <iostream>
#include <iomanip>

double ePowerMinusXApprox(double& x, double& absError, unsigned int& numberMax) {
	double res = 1.0;
	double elemI = 1;
	double factorial = 1;
	int factorialMultiply = 2;
	double xPower = x;
	for (int i = 1; (i <= numberMax) && (absError < abs(elemI)); i++) {
		elemI = xPower / (factorial);
		res += ((i%2 == 1) ? -elemI : elemI);
		xPower *= x;
		factorial *= factorialMultiply;
		factorialMultiply += 1;
	}
	return res;
}

int calcOutputPrecision(double absError) {
	int n = 1;
	while (absError < 1) {
		absError *= 10;
	}
	return n;
}

int main() {

	setlocale(LC_ALL, "Russian");

	std::cout << "Введите погрешность: ";
	double absError = 0.0;
	std::cin >> absError;
	absError = abs(absError);
	if (!std::cin.good()) {
		std::cerr << "Некорректный ввод, завершение программы...";
		return 1;
	}

	std::cout << "Введите максимальное число слагаемых: ";
	unsigned int numberMax = 0;
	std::cin >> numberMax;
	if (!std::cin.good()) {
		std::cerr << "Некорректный ввод, завершение программы...";
		return 1;
	}

	std::cout << "Введите интервал: "; //Внимательно с тем какой больше какой меньше
	double x1 = 0.0, x2 = 0.0; //Ими задаётся направление
	std::cin >> x1 >> x2;
	if (!std::cin.good() || x1 >= x2) {
		std::cerr << "Некорректный ввод, завершение программы...";
		return 1;
	} 

	std::cout << "Введите шаг интервала: ";
	double dx = 0.0;
	std::cin >> dx;
	if (!std::cin.good() || dx <= 0.0) {
		std::cerr << "Некорректный ввод, завершение программы...";
		return 1;
	} else if (dx > abs(x1 - x2)) {
		std::cerr << "Некорректный ввод, шаг интервала не может быть больше длины интервала, завершение программы...";
		return 1;
	}

	//Output part
	int outputPrecision = calcOutputPrecision(absError);
	const int MORE = 5;
	std::cout << "Approximation\t" <<  "|"  << "\tcstdlib\n"; // TODO: fix it all!
	//std::cout << std::setprecision(outputPrecision + int(MORE)) << std::setw(20);
	double nextX = x1;
	double approxVal = 0.0;
	for(int i = 0; nextX <= x2; i++){
	//	approxVal = ePowerMinusXApprox(nextX, absError, numberMax);
	//	std::cout << approxVal << "\t|\t" << pow(2.71828182459045, -nextX) << '\n'; //TODO: replace 2.7... with e
		nextX = x1 + i * dx;
	}
	return 0;

	//todolist
	/*
		fix e
		fix output 
		beautify code
		recheck input
		throw exception on unmatched precision
	*/

	



}