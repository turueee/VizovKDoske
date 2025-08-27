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
	read_from_file(calls);
	std::srand(std::time(nullptr));
	std::set<int> count_calls;
	for (std::pair<std::string, int>call : calls)
		count_calls.insert(call.second);
	std::vector<int> counts(count_calls.begin(),count_calls.end());
	std::vector<std::vector<std::string>> names_calls(counts.size());
	for (size_t i = 0; i < counts.size(); ++i)
	{
		for (std::pair<std::string, int> call : calls)
			if (counts[i] == call.second)
				names_calls[i].push_back(call.first);
		delete_missing(names_calls[i], missing);
	}
	size_t i = 0;
	for (size_t u = 0; u < counts.size(); ++u)
		while (!names_calls[u].empty() && i < stud)
		{
			int random = std::rand() % names_calls[u].size();
			std::cout << names_calls[u][random] << std::endl;
			calls[names_calls[u][random]] += 1;
			names_calls[u].erase(names_calls[u].begin() + random);
			i++;
		}
	std::cout << std::endl;
	save_to_file(calls);
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
			file << name.first << ' ' << ((name.second>=0)?name.second:0) << '\n';
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