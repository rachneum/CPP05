#include "Form.hpp"
#include "Bureaucrat.hpp"//Necessaire pour ma fonction beSigned().

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called." << std::endl;
	if ((gradeToSign > 150) || (gradeToExecute > 150))
        throw GradeTooLowException();
    else if ((gradeToSign < 1) || (gradeToExecute < 1))
        throw GradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called." << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	std::cout << "Form assignment operator called." << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& b)//Signe le formulaire si il a le bon grade.
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute() << std::endl;
    return (out);
}
