#include "Set.h"

SetResult Set::add(std::string key) {
	if (count < size)
	{
		if (!contains(key))
		{
			keys[count] = key;
			count++;
			return SetResult::Success;
		}
		else {
			return SetResult::AlreadyIn;
		}
	}
	else {
		return SetResult::Full;
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
	std::cout << "Set contents: \n";
	for (int i = 0; i < count; i++) {
		std::cout << "[" << i << "]" << " = " << keys[i] << "\n";
	}
}