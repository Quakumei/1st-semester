// var 5
#include <iostream>
#include <assert.h> /* assert */
#include <functional>

bool isLetter(char * str){
	switch (*str) {
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
		return true;
	default:
		return false;
	}
}
bool isLetter(const char* &str) {
	switch (*str) {
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
		return true;
	default:
		return false;
	}
}
bool isIdentificator(char* str) {
	return isLetter(str);
}
bool isIdentificator(const char*& str) {
	return isLetter(str);
}
bool isDigit(char* str) {
	switch (*str) {
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '0':
		return true;
	default:
		return false;
	}
}
bool isDigit(const char* &str) {
	switch (*str) {
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '0':
		return true;
	default:
		return false;
	}
}

bool tests() {
	return true;
}

int main() {
	std::cout << "Running tests... ";
	if (!tests()) {
		std::cerr << "bad";
		return 1;
	}
	else {
		std::cout << "OK.\n";
	}

	std::cout << "\n1################################\n";
	int size = 3;
	const char** ta = new const char* [size];
	for (int i = 0; i < size; ++i)
	{
		ta[i] = new char[size];
	}
	ta[0] = "123";
	ta[1] = "A10";
	ta[2] = "7A9";
	for (int i = 0; i < size; i++) {
		const char * cur = ta[i];
		std::cout << "test: " << cur << "\nresult: ";
		std::cout << isDigit(cur) << "\n\n";
	}

	std::cout << "\n2################################\n";
	size = 3;
	const char** ta1 = new const char* [size];
	for (int i = 0; i < size; ++i)
	{
		ta1[i] = new char[size];
	}
	ta1[0] = "123";
	ta1[1] = "A10";
	ta1[2] = "7A9";
	for (int i = 0; i < size; i++) {
		const char* cur = ta1[i];
		std::cout << "test: " << cur << "\nresult: ";
		std::cout << isLetter(cur) << "\n\n";
	}

	std::cout << "\n3################################\n";
	size = 3;
	const char** ta2 = new const char* [size];
	for (int i = 0; i < size; ++i)
	{
		ta2[i] = new char[size];
	}
	ta2[0] = "123";
	ta2[1] = "A10";
	ta2[2] = "7A9";
	for (int i = 0; i < size; i++) {
		const char* cur = ta2[i];
		std::cout << "test: " << cur << "\nresult: ";
		std::cout << isIdentificator(cur) << "\n\n";
	}

	std::cout << "\n4################################\n";
	size = 5;
	const char** ta3 = new const char* [3];
	for (int i = 0; i < 3; ++i)
	{
		ta3[i] = new char[size];
	}
	ta3[0] = "1234\0";
	ta3[1] = "123F\0";
	ta3[2] = "9999\0";
	for (int i = 0; i < 3; i++) {
		const char* cur = ta3[i];
		std::cout << "test: " << cur << "\nresult: ";
		std::cout << isIdentificator(cur) << "\n\n";
	}

	

	return 0;
}
