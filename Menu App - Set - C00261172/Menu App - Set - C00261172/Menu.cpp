#include "Menu.h"

void Menu::run() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int selection = 0;
	while (true) // MAIN LOOP
	{
		while (true) // Loop to check if user has inputted correct data type
		{
			// Starting text
			std::cout << "Text based Menu for Set class by Chi\n\t1) Create Set\n\t2) Add to Set\n\t3) Print Set\n\t4) Remove All from Set\n\t5) Contains in Set\n\t6) Remove From Set\n\nEnter an Option: ";
			std::cin >> selection;
			if (!std::cin.fail()) {
				break;
			}
			SendError("Error: Numbers only.\n\n");
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		std::cout << "\n";
		switch (selection) // Menu system
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
		case 6:
			removeFromSet();
			break;
		default:
			std::cout << "Invalid Selection\n\n";
			break;
		}
	}
}

/// <summary>
/// Ask user to input a name for the set,
/// if another set is found with the name then
/// repeat the question.
/// If not then continue to the next question
/// Ask the user for the set size.
/// If the inputted value is not a number then
/// repeat the question.
/// If not then create the set with the given values with
/// Set name being the index for the map to reference by and
/// Set Size being the size of the set
/// </summary>
void Menu::createSet() {
	std::string setName;
	int setSize = 1;

	while (true) {
		std::cout << "Enter the name of the new set: ";
		std::cin >> setName;
		if (!findSet(setName)) { // Check if set isn't inside of the map
			break;
		}
		SendError("\nAnother Set with the same name was already made.\n\n");
		if (!continueOperation()) {
			return; // EXIT FUNCTION
		}
	}
	while (true) {
		std::cout << "\nEnter the size of the new set: \n";
		std::cin >> setSize;
		if (!std::cin.fail()) {
			break;
		}
		SendError("Error: Numbers only.\n");
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	sets[setName] = std::make_unique<Set>(setSize); // Create a unique pointer for the set
	SendSuccess("Set: " + setName + " | Size: " + std::to_string(setSize) + " was created.\n\n");
}

/// <summary>
/// Ask user for set and ask them for a value to add into the Set,
/// if the Set is full, then display that it's full
/// if the Set already has the value, then display that it already has the value
/// if the Set doesn't have the value and it isn't full then display that it was successful
/// </summary>
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
			SendSuccess("Successfully added '" + value + "' to Set: " + setName + "\n");
			break;
		case SetResult::AlreadyIn:
			SendError("Unable to add '" + value + "' to Set: " + setName + "\n", "Key is already inside of the Set.\n");
			break;
		case SetResult::Full:
			SendError("Unable to add '" + value + "' to Set: " + setName + "\n", "Set is full.\n");
			break;
		}
		if (!continueOperation()) {
			return; // EXIT FUNCTION
		}
	}
}

/// <summary>
/// Ask the user for a Set and
/// Call the print function in the Set class
/// </summary>
void Menu::printSet() {
	listSets();
	std::string setName;

	setName = askForSet("");
	if (setName == "") { return; }

	sets[setName]->print();
	std::cout << "\n";
}

/// <summary>
/// Ask for 2 Sets and remove all the keys inside of set1 that are also in set2
/// </summary>
void Menu::removeAllFromSet() {
	listSets();
	std::string setName1;
	std::string setName2;

	setName1 = askForSet("[1] ");
	if (setName1 == "") { return; }
	setName2 = askForSet("[2] ");
	if (setName2 == "") { return; }

	SendSuccess("Removed " + std::to_string(sets[setName1]->removeAll(sets[setName2])) + " keys inside of the Set: " + setName1 + "\n\n");
}

/// <summary>
/// Ask the user for Set and find the value they inputted inside of the Set
/// </summary>
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
		SendSuccess("Found '" + input + "' inside of the Set: " + setName + "\n");
	}
	else {
		SendError("'" + input + "' wasn't found inside of the Set: " + setName + "\n");
	}
	std::cout << "\n";
}

/// <summary>
/// Ask user for set.
/// If they have entered a valid Set then
/// Ask user to delete a key from the Set,
/// If the key isn't found then warn them
/// If the key is found then remove the key from the Set and send them a success message
/// </summary>
void Menu::removeFromSet() {
	listSets();
	std::string setName;
	std::string input;

	setName = askForSet("");
	if (setName == "") { return; }
	sets[setName]->print();
	std::cout << "\n";

	while (true) {
		while (true) {
			std::cout << "Enter a value you want to remove from the Set: " << setName << "\n";
			std::cin >> input;
			if (sets[setName]->remove(input)) {
				break;
			}
			SendError("'" + input + "' wasn't found inside of the Set: " + setName + "\n\n");
			if (!continueOperation()) {
				return;
			}
		}
		SendSuccess("'" + input + "' was removed from the Set: " + setName + "\n\n");
		if (!continueOperation()) {
			return;
		}
	}

}

/// <summary>
/// Ask user if they would like to continue operation
/// </summary>
/// <returns>True = continue/ False = stop</returns>
bool Menu::continueOperation() {
	bool continueOp = false;
	while (true) {
		std::cout << "Would you like to continue:\n\t0 = No\n\t1 = Yes\n\nEnter an Option: ";
		std::cin >> continueOp;
		if (!std::cin.fail()) {
			break;
		}
		SendError("\nError: 0 or 1\n\n");
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	std::cout << "\n";
	return continueOp;
}

/// <summary>
/// Checks if the set is available in the map
/// </summary>
/// <param name="setName">Set Name</param>
/// <returns>True = Found | False = not Found</returns>
bool Menu::findSet(std::string setName) {
	return sets.find(setName) != sets.end();
}

/// <summary>
/// Ask the user for a set name,
/// If a set is found then break out of the loop,
/// If there is no set then the user can exit out of the loop
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
std::string Menu::askForSet(std::string index) {
	std::string setName;
	while (true)
	{
		std::cout << index << "Enter the name of your set: ";
		std::cin >> setName;
		// This if statement checks if the name of the set is in the map
		if (findSet(setName)) {
			break;
		}
		SendError("\nSet not found.\n\n");
		if (!continueOperation()) {
			return ""; // EXIT FUNCTION
		}
	}
	std::cout << "\n";
	return setName;
}

/// <summary>
/// Loop through all of the keys inside of the sets map
/// </summary>
void Menu::listSets() {
	std::string setsString;
	for (std::map<std::string, std::unique_ptr<Set>>::iterator iter = sets.begin(); iter != sets.end(); ++iter)
	{
		setsString = setsString + "||" + iter->first;
	}
	setsString = setsString + "||\n\n";
	std::cout << "Set Names: " << setsString;
}

/// <summary>
/// Send success message with green colour
/// </summary>
/// <param name="successMessage"></param>
void Menu::SendSuccess(std::string successMessage) {
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << successMessage;
	SetConsoleTextAttribute(hConsole, WHITE);
}

/// <summary>
/// Send error message with red colour
/// </summary>
/// <param name="errorMessage"></param>
void Menu::SendError(std::string errorMessage) {
	SetConsoleTextAttribute(hConsole, RED);
	std::cout << errorMessage;
	SetConsoleTextAttribute(hConsole, WHITE);
}

/// <summary>
/// Send Error message with red and grey colour
/// </summary>
/// <param name="errorMessage"></param>
/// <param name="extraMessage"></param>
void Menu::SendError(std::string errorMessage, std::string extraMessage) {
	SetConsoleTextAttribute(hConsole, RED);
	std::cout << errorMessage;
	SetConsoleTextAttribute(hConsole, GREY);
	std::cout << extraMessage;
	SetConsoleTextAttribute(hConsole, WHITE);
}