#include "Set.h"

void Set::add(std::string key) {
	if (count < size)
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

void Set::removeAll(std::unique_ptr<Set> &otherSet) {
	std::string* previousKeys = keys;
	int previousCount = count;
	count = 0;
	keys = (new std::string[size]);
	for (int i = 0; i < count; i++) {
		bool found = otherSet->contains(previousKeys[i]);
		if (!found) {
			add(previousKeys[i]);
		}
	}
	delete[] previousKeys;
}

void Set::print() {
	for (int i = 0; i < count; i++) {
		std::cout << "[" << i << "]" << " = " << keys[i] << "\n";
	}
}