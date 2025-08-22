#include "front.h"

void menu(std::map<std::string, size_t>& calls, std::vector<std::string>& names, const std::vector<std::string>& missing, std::vector<std::string>& in_names)
{
	while (true)
	{
		std::cout << "Options:\n"
			<< 1 << " - Call students\n"
			<< 2 << " - Plus point\n"
			<< 3 << " - Minus point\n"
			<< 4 << " - Save data and end program" << std::endl;
		size_t order;
		std::cin >> order;
		switch (order)
		{
		case 1:
			call_students(calls, names, missing);
			continue;
		case 2:
			plus_point(calls, in_names);
			continue;
		case 3:
			minus_point(calls, in_names);
			continue;
		case 4:
			return;
		}

	}
}

void call_students(std::map<std::string, size_t>& calls, std::vector<std::string> names, const std::vector<std::string>& missing)
{
	size_t stud = 0;
	std::cout << "Enter the count of students:\n";
	std::cin >> stud;
	if (stud > names.size() || stud < 0)
	{
		std::cerr << "Error count\n";
		return;
	}
	k_doske(stud, calls, missing);
	fuel_names(names, missing);
}

void ask_missing(std::vector<std::string>& names)
{
	std::cout << "Enter names of missing students:\n";
	while (true)
	{
		std::string name;
		std::cout << "Enter name:";
		std::getline(std::cin, name);
		if (name == "end")
			break;
		names.push_back(name);
	}
}