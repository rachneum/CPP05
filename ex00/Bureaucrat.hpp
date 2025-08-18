#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat
{
	private:
		const std::string	_name;//_name ici est const càd une fois qu'il a recu une valeur lors de la contruction de l'objet, elle ne pourra plus être modifiée.
		int					_grade;//(Ranges from 1(highest garde poss) to 150(lowest grade poss)).

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);//Vérifier ici si grade < 1 ou > 150.
		Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName() const;//const pour mes getters afin de m'assurer d'uniquement lire les attributs et jamais les modifier.
		int			getGrade() const;//const d'autant plus car mon attribut _name est const.

		void		incrementGrade();
		void		decrementGrade();

	/*Exception classes*/
	class	GradeTooHighException : public std::exception
	{
		public://what(): Fonction utilisée pour obtenir un message clair et précis lorsque l'exception est interceptée dans un bloc catch.
			const char*	what() const throw();//throw() ici est une spécification d'exception qui garantit que cette fonction ne lance pas d'exception elle-même.
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif