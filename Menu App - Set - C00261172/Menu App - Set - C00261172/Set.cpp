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

int Set::removeAll(std::unique_ptr<Set> &otherSet) {
	std::string* previousKeys = keys;
	int previousCount = count;
	count = 0;
	keys = (new std::string[size]);
	for (int i = 0; i < count; i++) {
		bool found = otherSet->contains(previousKeys[i]);
		if (!found) { // If the other set doesn't contain the key then add the key to the new set
			add(previousKeys[i]);
		}
	}
	delete[] previousKeys;
	return previousCount - count;
}

void Set::print() {
	std::cout << "Set contents: \n";
	for (int i = 0; i < count; i++) {
		std::cout << "[" << i << "]" << " = " << keys[i] << "\n";
	}
}

/// <summary>
/// Searches through the keys array and if the key passed in the function is found then
/// Loop from its index to count - 1 replacing the current key with the next key
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
bool Set::remove(std::string key) {
	int indexFound = 0;
	for (int i = 0; i < count; i++) {
		if (keys[i] == key) {
			indexFound = i + 1;
			break;
		}
	}
	if (indexFound) {
		indexFound -= 1;
		for (int i = indexFound; i < count - 1; i++) {
			keys[i] = keys[i + 1];
		}
		count--;
		keys[count] = "";
		return true;
	}
	return false;
}