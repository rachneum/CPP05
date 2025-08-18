#include "Bureaucrat.hpp"

int main()
{
    try
	{
        std::cout << "---- Test constructeur par défaut ----" << std::endl;
        Bureaucrat	b1;
        std::cout << b1.getName() << " grade: " << b1.getGrade() << std::endl;

        std::cout << "\n---- Test constructeur avec paramètres valides ----" << std::endl;
        Bureaucrat	b2("Alice", 42);
        std::cout << b2.getName() << " grade: " << b2.getGrade() << std::endl;

        std::cout << "\n---- Test copy constructor ----" << std::endl;
        Bureaucrat	b3(b2);
        std::cout << b3.getName() << " grade: " << b3.getGrade() << std::endl;

        std::cout << "\n---- Test assignment operator ----" << std::endl;
        Bureaucrat	b4("Bob", 100);
        b4 = b2;
        std::cout << b4.getName() << " grade: " << b4.getGrade() << std::endl;

        std::cout << "\n---- Test incrementGrade ----" << std::endl;
        b2.incrementGrade();//Devrait passer de 42 -> 41.
        std::cout << b2.getName() << " grade: " << b2.getGrade() << std::endl;

        std::cout << "\n---- Test decrementGrade ----" << std::endl;
        b2.decrementGrade();//Retour à 42.
        std::cout << b2.getName() << " grade: " << b2.getGrade() << std::endl;

        std::cout << "\n---- Test exceptions constructeur ----" << std::endl;
        try
		{
            Bureaucrat b5("TooLow", 200);//grade > 150
        }
		catch (std::exception &e)
		{
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try
		{
            Bureaucrat b6("TooHigh", 0);//grade < 1
        }
		catch (std::exception &e)
		{
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << "\n---- Test exceptions increment/decrement ----" << std::endl;
        Bureaucrat	top("Top", 1);
        try
		{
            top.incrementGrade();//Doit lancer GradeTooHighException.
        }
		catch (std::exception &e)
		{
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        Bureaucrat bottom("Bottom", 150);
        try
		{
            bottom.decrementGrade();//Doit lancer GradeTooLowException.
        }
		catch (std::exception &e)
		{
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
	catch (std::exception &e)
	{
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return (0);
}
