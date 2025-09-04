#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
	private:
	const std::string 	m_name;
	bool				m_bisSigned;
	const int			m_signRequirement;
	const int			m_execRequirement;

	public:
	Form();
	Form(std::string _name, bool _isSigned, const int _signRequirement, const int _execRequirement);
	Form(const Form& _other);
	Form& operator=(const Form& _other);
	~Form();

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getSignRequirement(void) const;
	int			getExecRequirement(void) const;
	void		beSigned(const Bureaucrat& _bureaucrat);

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
