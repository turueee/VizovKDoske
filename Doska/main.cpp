#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

void fuel_names(std::vector<std::string>& _names)
{
	_names.resize(15);
	_names[0] = "Volkov Roman";
	_names[1] = "Galochkin Dmitriy";
	_names[2] = "Gerasimov Andrey";
	_names[3] = "Katsina Polina";
	_names[4] = "Liashev Artem";
	_names[5] = "Milto Oleg";
	_names[6] = "Minin Iliya";
	_names[7] = "Mishin Pavel";
	_names[8] = "Porfiriev Mihail";
	_names[9] = "Ribakov Artem";
	_names[10] = "Sipailo Maxim";
	_names[11] = "Strelkov Kirill";
	_names[12] = "Turushkin Egor";
	_names[13] = "Federova Ksenya";
	_names[14] = "Yanaliev Maxim";
}

void k_doske(std::vector<std::string>& _names,size_t stud, size_t* max)
{
	for (size_t i = 0; i < stud; ++i)
	{
		std::srand(std::time(nullptr));
		int random = std::rand() % (*max)--;
		std::cout << _names[random] << std::endl;
		_names.erase(_names.begin() + random);
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> names(15);
	fuel_names(names);
	size_t max = 15, stud;
	while (true)
	{
		std::cout << "Enter the count of students:\n";
		std::cin >> stud;
		if (stud == -1)
			break;
		if (stud > 15)
		{
			std::cout << "Size error\n";
			continue;
		}
		if (stud <= max)
		{
			k_doske(names, stud, &max);
		}
		else
		{
			fuel_names(names);
			max = 15;
			k_doske(names, stud, &max);
		}
	}
}