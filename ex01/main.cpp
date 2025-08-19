#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
	{
        Bureaucrat b("Alice", 50);
        Form f("FormA", 100, 30);

        b.signForm(f);
        std::cout << f;
    }
    catch (std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return (0);
}
