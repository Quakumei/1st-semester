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



	friend std::istream& operator>>(std::istream& is, Subscriber& sub);
	friend std::ostream& operator<<(std::ostream& os, Subscriber& sub);

private:
	string name_;
	string surname_;
	string phone_;
	string tariff_;

};

#endif