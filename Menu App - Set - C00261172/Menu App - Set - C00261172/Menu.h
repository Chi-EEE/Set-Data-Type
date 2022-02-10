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

	void removeFromSet();

private:
	HANDLE hConsole;

	std::map<std::string, std::unique_ptr<Set>> sets;

	bool continueOperation();
	bool findSet(std::string setName);
	std::string askForSet(std::string index);
	void listSets();
	void SendSuccess(std::string successMessage);
	void SendError(std::string errorMessage);
	void SendError(std::string errorMessage, std::string extraMessage);
};

