#include <iostream>


// <знак> ::= +|- 
bool isSign(char* str) {
	if (*str == '+' || *str == '-') {
		str++;
		return true;
	}
	return false;
}

bool isSign(const char*& c) {
	if (*c == '+' || *c == '-') {
		c++;
		return true;
	}
	return false;
}

//<вещественное> ::= <мантисса> <порядок> | <знак> <мантисса> <порядок>
bool isRealNumber(const char*& str) {
	isSign(str);
	return isMantissa(str) && isExhibitor(str) && *str == '\0';
}

// <вещественное> ::= <мантисса><порядок>

bool isRealNumber(const char** expression)
{
	if (isMantissa(expression)) {
		if (isExhibitor(expression)) {
			return (**expression == '\0'); // вернуть true, если число состоит
			// только из мантиссы и экспоненты 
			//(после экспоненты больше ничего нет)
		}
	}
	else {
		return false;
	}
}