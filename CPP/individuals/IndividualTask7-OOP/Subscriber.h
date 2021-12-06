#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
#include <iostream>
typedef std::string string;

class Subscriber {
public:

	Subscriber(string&, string&, string&, string&);
	
	const string& getName() const;
	const string& getSurname() const;
	const string& getPhone() const;
	const string& getTariff() const;

	void setName(const string& value);
	void setSurname(const string& value);
	void setPhone(const string& value);
	void setTariff(const string& value);



	std::istream& operator>>(Subscriber& s);
	std::ostream& operator<<(Subscriber& s);

private:
	string name_;
	string surname_;
	string phone_;
	string tariff_;

};

#endif