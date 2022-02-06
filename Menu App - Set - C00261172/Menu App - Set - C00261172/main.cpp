#include "Set.h"
#include <iostream>

int main() {
	Set set1 = Set{ 10 };

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

	std::cout << "Set1:" << set1.getKeys() << "\n";

	std::cout << "\n";

	Set set2 = Set{ 5 };

	set2.add("Hello");
	set2.add("This");
	set2.add("Is");
	set2.add("My");
	set2.add("Program");

	set2.print();
	std::cout << "Set2:" << set2.getKeys() << "\n";

	set1.removeAll(set2);

	std::cout << "Set1:" << set1.getKeys() << "\n";
	set1.print();
	std::cout << "\n";

	system("pause");
	return 0;
}