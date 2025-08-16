#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{
    std::cout << "Other bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default destructor called." << std::endl;
}

