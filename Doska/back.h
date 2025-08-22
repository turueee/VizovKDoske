#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>

void fuel_names(std::vector<std::string>& _names, const std::vector<std::string>& missing);
void delete_missing(std::vector<std::string>& _names, const std::vector<std::string>& missing);
void first_save(std::vector<std::string>& names);
int min(std::map<std::string, size_t> calls);
void k_doske(const size_t stud, std::map<std::string, size_t>& calls, std::vector<std::string> missing);
void read_from_file(std::map<std::string, size_t>& calls);
void save_to_file(std::map<std::string, size_t>& calls);
void plus_point(std::map<std::string, size_t>& calls, std::vector<std::string>& in_names);
void minus_point(std::map<std::string, size_t>& calls, std::vector<std::string>& in_names);
