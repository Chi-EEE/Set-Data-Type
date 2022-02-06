#pragma once
#include <string>
#include <iostream>

public class Set
{
public:
	Set(int size) {
		this->size = size;
		keys = (new std::string[size]);
	};
	~Set() {
		delete[] keys;
	}
	void add(std::string key);
	bool contains(std::string key);
	void removeAll(Set& otherSet);
	void print();
	std::string* getKeys() { return keys; }
private:
	int size = 0;
	int count = 0;
	std::string* keys;
};