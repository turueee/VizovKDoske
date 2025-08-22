#include "back.h"


void fuel_names(std::vector<std::string>& names, const std::vector<std::string>& missing)
{
	names = {
		"Volkov Roman",
		"Galochkin Dmitriy",
		"Gerasimov Andrey",
		"Katsina Polina",
		"Liashev Artem",
		"Milto Oleg",
		"Minin Iliya",
		"Mishin Pavel",
		"Porfiriev Mihail",
		"Ribakov Artem",
		"Sipailo Maxim",
		"Strelkov Kirill",
		"Turushkin Egor",
		"Federova Ksenya",
		"Yanaliev Maxim"
	};
	delete_missing(names, missing);
}

void delete_missing(std::vector<std::string>& _names, const std::vector<std::string>& missing)
{
	for (std::string absent : missing)
	{
		auto it = std::find(_names.begin(), _names.end(), absent);
		if (it != _names.end()) {
			_names.erase(it);
		}
	}
}

void first_save(std::vector<std::string>& names)
{
	std::vector<std::string> missing;
	fuel_names(names, missing);
	std::ofstream file("calls.txt");
	if (file.is_open())
		for (std::string name : names)
		{
			file << name << ' ' << 0 << '\n';
		}
	file.close();
}

int min(std::map<std::string, size_t> calls)
{
	size_t min = 1000;
	for (std::pair<std::string, size_t> call : calls)
		min = (min > call.second) ? call.second : min;
	return min;
}

void k_doske(const size_t stud, std::map<std::string, size_t>& calls, std::vector<std::string> missing)
{
	std::srand(std::time(nullptr));
	std::vector<std::string> min_calls, max_calls;
	size_t minim = min(calls), i = 0;
	for (std::pair<std::string, size_t> call : calls)
	{
		if (call.second == minim)
			min_calls.push_back(call.first);
		else
			max_calls.push_back(call.first);
	}
	delete_missing(min_calls, missing);
	delete_missing(max_calls, missing);
	while (!min_calls.empty() && i < stud)
	{
		int random = std::rand() % min_calls.size();
		std::cout << min_calls[random] << std::endl;
		calls[min_calls[random]] += 1;
		min_calls.erase(min_calls.begin() + random);
		i++;
	}
	while (!max_calls.empty() && i < stud)
	{
		int random = std::rand() % max_calls.size();
		std::cout << max_calls[random] << std::endl;
		calls[max_calls[random]] += 1;
		max_calls.erase(max_calls.begin() + random);
		i++;
	}
	std::cout << std::endl;
}

void read_from_file(std::map<std::string, size_t>& calls)
{
	std::ifstream file("calls.txt");
	std::string line;
	if (file.is_open())
		while (std::getline(file, line))
		{
			std::string name(line.begin(), line.begin() + line.find_last_of(' ')), count_of_calls(line.begin() + line.find_last_of(' ') + 1, line.end());
			calls[name] = atoi(count_of_calls.c_str());
		}
	file.close();
}

void save_to_file(std::map<std::string, size_t>& calls)
{
	std::ofstream file("calls.txt");
	if (file.is_open())
		for (std::pair<std::string, int> name : calls)
		{
			file << name.first << ' ' << name.second << '\n';
		}
	file.close();
}

void plus_point(std::map<std::string, size_t>& calls, std::vector<std::string>& in_names)
{
	for (std::string name : in_names)
		calls[name]++;
}

void minus_point(std::map<std::string, size_t>& calls, std::vector<std::string>& in_names)
{
	for (std::string name : in_names)
		calls[name]--;
}