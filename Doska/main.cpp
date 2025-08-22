#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "front.h"
#include "back.h"

int main()
{
	std::fstream file("calls.txt");
	std::vector<std::string> names(15);
	std::map<std::string, size_t> calls;
	std::vector<std::string> in_names,missing;
	first_save(names);
	ask_missing(missing);
	fuel_names(names,missing);
	read_from_file(calls);
	menu(calls, names,missing,in_names);
	fuel_names(names,missing);
	save_to_file(calls);
	file.close();
}