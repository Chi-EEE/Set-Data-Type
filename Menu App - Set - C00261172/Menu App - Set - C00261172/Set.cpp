#include "Set.h"
#include <iostream>

void Set::add(std::string key) {
	if (count + 1 < size)
	{
		if (!contains(key))
		{
			std::cout << "Added " << key << " at index " << count << " in Set of size " << size << "\n";
			keys[count] = key;
			count++;
		}
		else {
			std::cout << "Unable to add key: '" << key << "'. Key is already valid in the Set of size: " << size << "\n";
		}
	}
	else {
		std::cout << "Unable to add key: '" << key << "'. Attempt to add key at index " << count << " with Set of size: " << size << "\n";
	}
}

bool Set::contains(std::string key) {
	for (int i = 0; i < count; i++) {
		if (keys[i] == key) {
			return true;
		}
	}
	return false;
}

void Set::removeAll(Set otherSet) {
	std::string* newSet = (new std::string[size]);
	int newCount = 0;
	for (int i = 0; i < count; i++) {
		bool found = otherSet.contains(keys[i]);
		if (!found) {
			newSet[newCount] = keys[i];
			newCount++;
		}
	}
	delete[] keys;
	count = newCount;
	keys = newSet;
}