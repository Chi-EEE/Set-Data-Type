/// <summary>
/// Name: Huu Chi Huynh
/// Date: 07/02/2022
/// </summary>

#include "Menu.h"
#include "Set.h"
#include <iostream>

//void getColours() {
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	// you can loop k higher to see more color choices
//	for (int k = 0; k < 255; k++)
//	{
//		// pick the colorattribute k you want
//		SetConsoleTextAttribute(hConsole, k);
//		std::cout << k << " I want to be nice today!" << std::endl;
//	}
//}

int main() {
	//getColours();
	Menu menu = Menu{};
	menu.run();
	/*Set set1 = Set{ 10 };

	set1.add("Hello");
	set1.add("World");
	set1.add(".");
	set1.add("My");
	set1.add("Name");
	set1.add("Is");
	set1.add("Chi");
	set1.add(".");
	set1.add("I");
	set1.add("Am");
	set1.add("Writing");

	set1.print();

	std::cout << "\n";

	Set set2 = Set{ 5 };

	set2.add("Hello");
	set2.add("This");
	set2.add("Is");
	set2.add("My");
	set2.add("Program");

	set2.print();

	set1.removeAll(set2);
	set1.print();
	std::cout << "\n";*/

	system("pause");
	return 0;
}