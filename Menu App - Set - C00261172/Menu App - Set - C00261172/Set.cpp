#include "Set.h"

/// <summary>
/// Check if the count is less than size,
/// If not then return SetResult::Full.
/// If less then check if the key is not inside of the keys array.
/// If found then return SetResult::AlreadyIn.
/// Else add the key to the keys array and increase the count returning SetResult::Success
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
SetResult Set::add(std::string key) {
	if (count < size)
	{
		if (!contains(key))
		{
			keys[count] = key;
			count++;
			return SetResult::Success; // Returning this enum for Menu app
		}
		else {
			return SetResult::AlreadyIn;
		}
	}
	else {
		return SetResult::Full;
	}
}

/// <summary>
/// Loops through the keys array using linear search 
/// checking if the key param is equal to the looped key
/// If the key is found inside of the array then return true else false
/// </summary>
/// <param name="key"></param>
/// <returns>True = found | False = not found</returns>
bool Set::contains(std::string key) {
	for (int i = 0; i < count; i++) {
		if (keys[i] == key) {
			return true;
		}
	}
	return false;
}

/// <summary>
/// Keep reference of previous keys array and previous count.
/// Reset the current keys and count.
/// Loop through the previous keys array and check if it is inside of the other set.
/// If the key isnt found inside of the other set then add that key to keys array
/// After finished looping through previous keys array,
/// Delete the previous keys array and return the amount of keys removed
/// </summary>
/// <param name="otherSet">Other set to compare and remove the current Set's keys</param>
/// <returns>Amount of keys removed</returns>
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
	delete[] previousKeys; // Delete previous keys array
	return previousCount - count; // Amount of keys removed from the keys array
}

/// <summary>
/// Go through the keys array printing all of the Set contents
/// </summary>
void Set::print() {
	std::cout << "Set contents: \n";
	for (int i = 0; i < count; i++) {
		std::cout << "[" << i << "]" << " = " << keys[i] << "\n";
	}
}

/// <summary>
/// Searches through the keys array using linear search and if the key passed in the function is found then
/// return the index of the key + 1
/// 
/// TAKE 1 away from RESULT
/// </summary>
/// <param name="key"></param>
/// <returns>keyIndex + 1 [Take 1 away from it to get index]</returns>
int Set::search(std::string key) {
	int indexFound = 0; // If key isn't found then indexFound will be 0 which is false
	for (int i = 0; i < count; i++) {
		if (keys[i] == key) {
			indexFound = i + 1;
			break;
		}
	}
	return indexFound; // - 1 if in use
}

/// <summary>
/// Loop from its index to count - 1 replacing the current key with the next key
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
bool Set::remove(std::string key) {
	int indexFound = search(key); // No need to check if the count is equal to or below 0
	if (indexFound) {
		indexFound -= 1;
		// Loop from the indexFound to the count - 1 moving the key of i + 1 to index i
		for (int i = indexFound; i < count - 1; i++) {
			keys[i] = keys[i + 1];
		}
		count--;

		// The count index will always be the an empty string when this happens.
		// And to ensure that the program doesn't index outside of the keys array
		keys[count] = "";
		return true; // Return if remove is successful
	}
	return false;
}

/// <summary>
/// Reset count to 0 and
/// Delete all keys array and create a new one
/// [Not to be used with removeAll]
/// </summary>
void Set::clear() {
	count = 0;
	delete[] keys;
	keys = (new std::string[size]);
}

/// <summary>
/// Checks if the current set is equal to the other Set by
/// Looping through the current Set and checking if the other set doesn't contain the key
/// </summary>
/// <param name="otherSet"></param>
/// <returns></returns>
bool Set::equals(std::unique_ptr<Set>& otherSet) {
	if (otherSet->getCount() == count && otherSet->getSize()) {
		for (int i = 0; i < count; i++) {
			if (!otherSet->contains(keys[i])) {
				return false;
			}
		}
		return true;
	}
	return false;
}