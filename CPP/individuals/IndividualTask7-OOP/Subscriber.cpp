#include "Subscriber.h"
#include <iostream>

string const & Subscriber::getName() const{
	return name_; 
}

string const & Subscriber::getSurname() const{
	return surname_; 
}

string const & Subscriber::getPhone() const{
	return phone_; 
}

string const & Subscriber::getTariff() const{
	return tariff_; 
}

void Subscriber::setName(const string& value){
	this->name_ = value;
}
void Subscriber::setSurname(const string& value){
	this->surname_ = value;
}
void Subscriber::setPhone(const string& value){
	this->phone_ = value;
}
void Subscriber::setTariff(const string& value){
	this->tariff_ = value;
}



Subscriber::Subscriber(string name, string surname, string phone, string tariff){
	this->name_ = name;
	this->surname_ = surname;
	this->phone_ = phone;
	this->tariff_ = tariff;
}

std::istream& Subscriber::operator>>(std::istream& is, Subscriber& sub){
	//TODO: Input check vars 
	is >> sub.name_ >> sub.surname_ >> sub.phone_ >> sub.tariff_;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Subscriber& sub){
	os << "[ " << sub.name_ << " , " << sub.surname_ << " , "<< sub.phone_ << " , "<< sub.tariff_ << " ]\n"; 
	return os;
}