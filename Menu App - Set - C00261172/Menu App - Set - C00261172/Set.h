#pragma once
#include <string>

public class Set
{
public:
	Set(int x) {
		keys = (new std::string[x]);
		entries = (new std::string[x]);
	};
	~Set() {
		delete keys;
	}
	void add(std::string key, std::string entry);

	void contains(std::string key, std::string entry);

private:
	int count = 0;
	std::string* keys;
	std::string* entries;
};