#ifndef AForm_HPP
#define AForm_HPP

#include <string>

class Bureaucrat;

class AForm
{
	private:
	const std::string 	m_name;
	bool				m_bisSigned;
	const int			m_signRequirement;
	const int			m_execRequirement;

	public:
	AForm();
	AForm(std::string _name, bool _isSigned, const int _signRequirement, const int _execRequirement);
	AForm(const AForm& _other);
	AForm& operator=(const AForm& _other);
	virtual ~AForm();

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getSignRequirement(void) const;
	int			getExecRequirement(void) const;
	void		beSigned(const Bureaucrat& _bureaucrat);
	void		execute(Bureaucrat const & executor) const;
	virtual void executeAction() const = 0;

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

	class NotSignedException : public std::exception
	{
		private:
		std::string m_message;

		public:
		NotSignedException(const char * _msg);
		virtual ~NotSignedException() throw();
		virtual const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
