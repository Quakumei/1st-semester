#include <iostream>

//void printArray(int a[]) {
//	std::cout << "sizeof = " << sizeof(*(a)) << "[";
//	for (int i = 0; i <= sizeof(a); i++) {
//		std::cout << " " << a[i] << " ";
//	}
//	std::cout << ']';
//	return;
//}

// a[1] = 1[a] = *(1+a) = *(a+1)

int main() {
	int i = 10;
	int* d = new int[i]; // динамический массив

	//cpp - freestore (аналог heap в  c) 
	// freestore управляется new и delete
	d[0] = 100;
	*(d + 1) = 200;
	std::cout << d[0] << '\n';
	std::cout << d[1] << '\n';

	delete[] d; //так удаляется память для массива (с квадратными скобами)

	// в отличие от простых переменных массив всегда передается по ссылке

}