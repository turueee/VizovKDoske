#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include "back.h"
void menu(std::map<std::string, size_t>& calls, std::vector<std::string>& names, const std::vector<std::string>& missing, std::vector<std::string>& in_names);
void call_students(std::map<std::string, size_t>& calls, std::vector<std::string> names, const std::vector<std::string>& missing);
void ask_missing(std::vector<std::string>& names);
void ask(std::vector<std::string>& names);