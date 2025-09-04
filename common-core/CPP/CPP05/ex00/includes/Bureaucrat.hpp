#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const 	std::string m_name;
	int		m_grade;
public:
	Bureaucrat();
	Bureaucrat(int _grade, std::string _name);
	Bureaucrat(const Bureaucrat& _other);
	Bureaucrat& operator=(const Bureaucrat& _other);
	~Bureaucrat();

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		increment(void);
	void		decrement(void);

	class GradeTooHighException : public std::exception
	{
		private:
		std::string m_message;

		public:
		GradeTooHighException(const char * _msg);
		virtual ~GradeTooHighException() throw();
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		private:
		std::string m_message;

		public:
		GradeTooLowException(const char * _msg);
		virtual ~GradeTooLowException() throw();
		virtual const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
