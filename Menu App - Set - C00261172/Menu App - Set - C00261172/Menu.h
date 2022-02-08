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
	void createSet();
	void addToSet();
	void listSets();
	void run();

private:
	std::map<std::string, Set*> sets;
};

