#pragma once
#include "Set.h"

#include <iostream>
#include <map>

public class Menu
{
public:
	~Menu() {
		sets.erase(sets.begin(), sets.end());
	}
	void run();
	void createSet();
	void addToSet();
	void printSet();
	void removeAllFromSet();
	void listSets();

private:
	std::map<std::string, Set*> sets;
};

