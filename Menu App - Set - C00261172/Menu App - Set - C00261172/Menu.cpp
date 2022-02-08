#include "Menu.h"

void Menu::showOptions() {
	std::cout << "Text based Menu for Set class by Chi\n\n\t1) Create Set\n\n";
}

void Menu::createSet() {
	std::string setName;
	int setSize = 1;

	std::cout << "Enter the name of the set: ";
	std::cin >> setName;
	while (true) {
		std::cout << "\nEnter the size of the set: ";
		std::cin >> setSize;
		if (!std::cin.fail()) {
			break;
		}
		std::cout << "Error: Numbers only." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	sets[setName] = Set{ setSize };
}

void Menu::processInput() {
	bool success = false;
	int selection = 0;
	while (!success)
	{
		std::cin >> selection;
		while (std::cin.fail()) {
			std::cout << "Error: Numbers only." << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> selection;
		}
		switch (selection)
		{
		case 1:
			createSet();
			success = true;
			break;
		default:
			std::cout << "Invalid Selection\n";
			break;
		}
	}
}

void Menu::run() {
	while (true)
	{
		showOptions();
		processInput();
	}
}