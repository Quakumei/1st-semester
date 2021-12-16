#pragma once
#include <iostream>
#include <functional>
#include "Subscriber.h"

class SubscriberList {
public:
	SubscriberList();
	~SubscriberList();

	void add(Subscriber s);
	void sort(std::function<bool(const Subscriber&, const Subscriber&)> compare);
	void printAll(std::ostream&) const;

	Subscriber& operator[](std::size_t pos) const;


private:
	static const int MULTIPLIER = 2;
	int size_;
	int capacity_;
	Subscriber** array_;
};


