#include <iostream>
#include <map>

int main()
{
// Create a map of strings to integers
std::map<std::string, int> map;

// Insert some values into the map
map["one"] = 1;
map["two"] = 2;
map["three"] = 3;

// Print the values in the map
std::cout << "Key: one, Value: " << map["one"] << std::endl;
std::cout << "Key: two, Value: " << map["two"] << std::endl;
std::cout << "Key: three, Value: " << map["three"] << std::endl;

// Check if a key is in the map
if (map.count("four") > 0)
{
	std::cout << "Key 'four' is in the map" << std::endl;
}
else
{
	std::cout << "Key 'four' is not in the map" << std::endl;
}

return 0;
}
