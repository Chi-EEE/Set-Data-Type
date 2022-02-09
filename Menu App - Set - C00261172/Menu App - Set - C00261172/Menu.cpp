#include "Menu.h"

void Menu::run() {
	int selection = 0;
	while (true) // MAIN LOOP
	{
		while (true)
		{
			std::cout << "Text based Menu for Set class by Chi\n\t1) Create Set\n\t2) Add to Set\n\t3) Print Set\n\t4) Remove All from Set\n";
			std::cin >> selection;
			if (!std::cin.fail()) {
				break;
			}
			std::cout << "Error: Numbers only.\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		switch (selection)
		{
		case 1:
			createSet();
			break;
		case 2:
			addToSet();
			break;
		case 3:
			printSet();
			break;
		case 4:
			removeAllFromSet();
			break;
		default:
			std::cout << "Invalid Selection\n\n";
			break;
		}
	}
}

void Menu::createSet() {
	std::string setName;
	int setSize = 1;

	std::cout << "Enter the name of the new set: ";
	std::cin >> setName;
	while (true) {
		std::cout << "\nEnter the size of the new set: ";
		std::cin >> setSize;
		if (!std::cin.fail()) {
			break;
		}
		std::cout << "Error: Numbers only." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	sets[setName] = std::make_unique<Set>(setSize);
}

/// <summary>
/// Ask user if they would like to continue operation
/// </summary>
/// <returns>True = continue/ False = stop</returns>
bool continueOperation(std::string error) {
	bool continueOp = false;
	while (true) {
		std::cout << error << "\nWould you like to continue:\n\t0 = No\n\t1 = Yes\n";
		std::cin >> continueOp;
		if (!std::cin.fail()) {
			break;
		}
		std::cout << "Error: 0 or 1" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	std::cout << "\n";
	return continueOp;
}

void Menu::addToSet() {
	listSets();
	std::string setName;
	bool continueAdd = false;

	while (true)
	{
		std::cout << "Enter the name of your set: ";
		std::cin >> setName;
		// This if statement checks if the name of the set is in the map
		if (sets.find(setName) != sets.end()) {
			break;
		}
		if (!continueOperation("\nSet not found")) {
			return; // EXIT FUNCTION
		}
	}
	while (true)
	{
		std::string value;
		std::cout << "Please enter the value that you are going to put into the Set '" << setName << "':\n";
		std::cin >> value;
		std::cout << "\n";
		sets[setName]->add(value);
		if (!continueOperation("")) {
			return; // EXIT FUNCTION
		}
	}
}

void Menu::printSet() {
	listSets();
	std::string setName;

	while (true)
	{
		std::cout << "Enter the name of your set: ";
		std::cin >> setName;
		// This if statement checks if the name of the set is in the map
		if (sets.find(setName) != sets.end()) {
			break;
		}
		if (!continueOperation("\nSet not found")) {
			return; // EXIT FUNCTION
		}
	}
	sets[setName]->print();
	std::cout << "\n";
}

void Menu::removeAllFromSet() {
	std::string set1Name;
	std::string set2Name;
	while (true)
	{
		std::cout << "Enter the name of your first set: ";
		std::cin >> set1Name;
		// This if statement checks if the name of the set is in the map
		if (sets.find(set1Name) != sets.end()) {
			break;
		}
		if (!continueOperation("\nSet not found")) {
			return; // EXIT FUNCTION
		}
	}
	while (true)
	{
		std::cout << "Enter the name of your second set: ";
		std::cin >> set2Name;
		// This if statement checks if the name of the set is in the map
		if (sets.find(set2Name) != sets.end()) {
			break;
		}
		if (!continueOperation("\nSet not found")) {
			return; // EXIT FUNCTION
		}
	}
	sets[set1Name]->removeAll(sets[set2Name]);
}

void Menu::listSets() {
	std::string setsString;
	// Loop through all of the values inside of the sets map
	for (std::map<std::string, std::unique_ptr<Set>>::iterator iter = sets.begin(); iter != sets.end(); ++iter)
	{
		setsString = setsString + "||" + iter->first;
	}
	setsString = setsString + "||\n\n";
	std::cout << "Set Names: " << setsString;
}