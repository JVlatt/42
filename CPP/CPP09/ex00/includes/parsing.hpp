#ifndef PARSING_HPP
#define PARSING_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

void	parse_input(std::map<std::string,float> _data, const char *_infile);
std::map<std::string,float> parse_data();

#endif
