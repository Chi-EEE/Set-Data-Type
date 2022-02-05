#pragma once
#include <string>

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
	void removeAll(Set otherSet);
	void print();
private:
	int size = 0;
	int count = 0;
	std::string* keys;
};