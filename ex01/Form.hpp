#ifndef  FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat;//Declaration anticipee, car ma methode (fonction membre) prend un parametre Bureaucrat.

class	Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);//std::string passé par référence const pour éviter la copie, int passé par valeur car léger, pas besoin de const.
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string	getName() const;//const a la fin de mes getters afin de m'assurer que les objets ne seront pas modifies.
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void	beSigned(const Bureaucrat& b);
		
	class	GradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif