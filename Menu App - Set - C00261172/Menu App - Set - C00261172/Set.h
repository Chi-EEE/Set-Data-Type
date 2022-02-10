#pragma once
#include <string>
#include <iostream>

enum class SetResult {
	Success,
	Full,
	AlreadyIn
};

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
	SetResult add(std::string key);
	bool contains(std::string key);
	int removeAll(std::unique_ptr<Set> &otherSet);
	void print();
	int search(std::string key);
	bool remove(std::string key);
	void clear();
	bool equals(std::unique_ptr<Set>& otherSet);

	const int getSize() { return size; }
	const int getCount() { return count; }

private:
	int size = 0;
	int count = 0;

	// When debugging, the size of the keys are set from the constructor
	std::string* keys;
};