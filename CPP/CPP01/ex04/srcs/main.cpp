#include <string>
#include <iostream>
#include <fstream>

void	ft_sed(std::ifstream &fin, std::ofstream &fout, std::string &s1, std::string &s2)
{
	std::string	iline;
	std::string	oline;
	std::size_t	found;

	while (fin)
	{
		oline.clear();
		getline(fin, iline);
		found = iline.find(s1);
		if (found != std::string::npos)
		{
			while (found != std::string::npos)
			{
				oline.append(iline, 0, found);
				oline.append(s2);
				iline = iline.substr(found + s1.length());
				found = iline.find(s1);
			}
			if (iline.length())
				oline.append(iline);
		}
		else
		{
			oline = iline;
		}
		fout << oline << std::endl;
	}
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
	if (s1.length() == 0 || s2.length() == 0)
	{
		std::cerr << "Error Empty Arguments !" << std::endl;
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
