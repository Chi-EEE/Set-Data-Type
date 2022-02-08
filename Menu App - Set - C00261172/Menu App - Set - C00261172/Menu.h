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
	void showOptions();
	void createSet();
	void processInput();
	void run();

private:
	std::map<std::string, Set> sets;
};

