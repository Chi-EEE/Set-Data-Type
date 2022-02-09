#include "Menu.h"

void Menu::run() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int selection = 0;
	while (true) // MAIN LOOP
	{
		while (true)
		{
			std::cout << "Text based Menu for Set class by Chi\n\t1) Create Set\n\t2) Add to Set\n\t3) Print Set\n\t4) Remove All from Set\n\t5) Contains in Set\n";
			std::cin >> selection;
			if (!std::cin.fail()) {
				break;
			}
			std::cout << "Error: Numbers only.\n\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		std::cout << "\n";
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
		case 5:
			containsInSet();
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
		std::cout << "Error: Numbers only.\n\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	sets[setName] = std::make_unique<Set>(setSize);
}

void Menu::addToSet() {
	listSets();
	std::string setName;
	bool continueAdd = false;

	setName = askForSet("");
	if (setName == "") { return; }

	while (true)
	{
		std::string value;
		std::cout << "Please enter the value that you are going to put into the Set '" << setName << "':\n";
		std::cin >> value;
		std::cout << "\n";
		switch (sets[setName]->add(value)) {
		case SetResult::Success:
			SetConsoleTextAttribute(hConsole, GREEN);
			std::cout << "Successfully added " << value << " to Set: " << setName << "\n";
			SetConsoleTextAttribute(hConsole, WHITE);
			break;
		case SetResult::AlreadyIn:
			SetConsoleTextAttribute(hConsole, RED);
			std::cout << "Unable to add " << value << " to Set: " << setName << "\n";
			SetConsoleTextAttribute(hConsole, GREY);
			std::cout << "Key is already inside of the Set.\n";
			SetConsoleTextAttribute(hConsole, WHITE);
			break;
		case SetResult::Full:
			SetConsoleTextAttribute(hConsole, RED);
			std::cout << "Unable to add " << value << " to Set: " << setName << "\nSet is full.";
			SetConsoleTextAttribute(hConsole, GREY);
			std::cout << "Set is full.\n";
			SetConsoleTextAttribute(hConsole, WHITE);
			break;
		}
		if (!continueOperation("")) {
			return; // EXIT FUNCTION
		}
	}
}

void Menu::printSet() {
	listSets();
	std::string setName;

	setName = askForSet("");
	if (setName == "") { return; }

	sets[setName]->print();
	std::cout << "\n";
}

void Menu::removeAllFromSet() {
	listSets();
	std::string setName1;
	std::string setName2;

	setName1 = askForSet("[1] ");
	if (setName1 == "") { return; }
	setName2 = askForSet("[2] ");
	if (setName2 == "") { return; }

	sets[setName1]->removeAll(sets[setName2]);
}

void Menu::containsInSet() {
	listSets();
	std::string setName;
	std::string input;

	setName = askForSet("");
	if (setName == "") { return; }

	std::cout << "Enter a value that will want to find in the Set: " << setName << "\n";
	std::cin >> input;

	std::cout << "\n";
	if (sets[setName]->contains(input)) {
		SetConsoleTextAttribute(hConsole, GREEN);
		std::cout << "Found '" << input << "' inside of the Set: " << setName << "\n";
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	else {
		SetConsoleTextAttribute(hConsole, RED);
		std::cout << "'" << input << "' wasn't found inside of the Set: " << setName << "\n";
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	std::cout << "\n";
}

/// <summary>
/// Ask user if they would like to continue operation
/// </summary>
/// <returns>True = continue/ False = stop</returns>
bool Menu::continueOperation(std::string error) {
	bool continueOp = false;
	while (true) {
		std::cout << error << "\nWould you like to continue:\n\t0 = No\n\t1 = Yes\n";
		std::cin >> continueOp;
		if (!std::cin.fail()) {
			break;
		}
		SetConsoleTextAttribute(hConsole, RED);
		std::cout << "Error: 0 or 1\n\n";
		SetConsoleTextAttribute(hConsole, WHITE);
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	std::cout << "\n";
	return continueOp;
}

std::string Menu::askForSet(std::string index) {
	std::string setName;
	while (true)
	{
		std::cout << index << "Enter the name of your set: ";
		std::cin >> setName;
		// This if statement checks if the name of the set is in the map
		if (sets.find(setName) != sets.end()) {
			break;
		}
		if (!continueOperation("\nSet not found.")) {
			return ""; // EXIT FUNCTION
		}
	}
	std::cout << "\n";
	return setName;
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
