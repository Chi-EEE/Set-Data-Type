#pragma once
#include <string>
#include <iostream>

class Set
{
public:
	Set() {
		this->size = 1;
		keys = (new std::string[1]);
	};
	Set(int size) {
		this->size = size;
		keys = (new std::string[size]);
	};
	~Set() {
		delete[] keys;
	}
	void add(std::string key);
	bool contains(std::string key);
	void removeAll(std::unique_ptr<Set> &otherSet);
	void print();
	std::string* getKeys() { return keys; }
private:
	int size = 0;
	int count = 0;

	// When debugging, the size of the keys are set from the constructor
	std::string* keys;
};