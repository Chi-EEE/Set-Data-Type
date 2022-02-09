#pragma once
#include "Set.h"

#include <iostream>
#include <map>			// Map data type for storing Sets
#include <windows.h>	// WinApi header
#include "Colour.h"		// Colours for the console

class Menu
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
	void containsInSet();

private:
	HANDLE hConsole;

	std::map<std::string, std::unique_ptr<Set>> sets;

	bool continueOperation(std::string error);
	std::string askForSet(std::string index);
	void listSets();
};

