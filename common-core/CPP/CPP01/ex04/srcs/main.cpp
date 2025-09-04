#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void	ft_sed(std::ifstream &fin, std::ofstream &fout, std::string &s1, std::string &s2)
{
	std::string			iline;
	std::string			oline;
	std::size_t			found;
	std::string			buffer;

	getline(fin, iline);
	while (fin)
	{
		buffer += iline + "\n";
		iline.clear();
		getline(fin, iline);
	}
	found = buffer.find(s1);
	while (found != std::string::npos)
	{
		oline.append(buffer, 0, found);
		if (s2.length() > 0)
			oline.append(s2);
		buffer = buffer.substr(found + s1.length());
		found = buffer.find(s1);
	}
	oline.append(buffer, 0);
	buffer.clear();
	fout << oline;
}

bool	check_files(char **argv, std::ifstream &fin, std::ofstream &fout)
{
	std::string	fout_name;

	fin.open(argv[1]);
	if (!fin)
	{
		std::cerr << "Error Opening Input File !" << std::endl;
		return (false);
	}
	fout_name = argv[1];
	fout_name.append(".replace");
	fout.open(fout_name.c_str());
	if (!fout)
	{
		std::cerr << "Error Creating Output File !" << std::endl;
		fin.close();
		return (false);
	}
	return (true);
}

bool	try_sed(char **argv)
{
	std::ofstream	fout;
	std::ifstream	fin;
	std::string		s1;
	std::string		s2;

	if (!check_files(argv, fin, fout))
		return (false);
	s1 = argv[2];
	s2 = argv[3];
	if (s1.length() == 0)
	{
		std::cerr << "Error Arg2 cannot be empty !" << std::endl;
		return (false);
	}
	ft_sed(fin, fout, s1, s2);
	fin.close();
	fout.close();
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong Number of arguments !" << std::endl;
		return (1);
	}
	else
	{
		if (!try_sed(argv))
			return (1);
	}
	return (0);
}
