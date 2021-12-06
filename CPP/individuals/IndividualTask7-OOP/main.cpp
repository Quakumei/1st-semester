#include <iostream>
#include <fstream>
#include "Subscriber.cpp"

int main(){
	Subscriber s = Subscriber("Gleb", "Zhukov", "+7961618937", "1+1=2");
	
	std::cout << "Name\t: " << s.getName() << '\n';
	std::cout << "Done!\n";
	return 0;
}
