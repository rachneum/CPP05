#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "---- Test 1 : Création de formulaires valides ----" << std::endl;
    try
    {
        Form f1("Tax Form", 50, 20);
        std::cout << f1 << std::endl;

        Form f2("Contract", 1, 1);
        std::cout << f2 << std::endl;

        Form f3("Leave Request", 150, 150);
        std::cout << f3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 2 : Création de formulaires invalides (exceptions) ----" << std::endl;
    try
    {
        Form bad1("Impossible Form", 0, 10);//grade trop haut.
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }
    try
    {
        Form bad2("Impossible Form", 200, 10); //grade trop bas.
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 3 : Bureaucrat signe un formulaire avec succès ----" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 40);
        Form tax("Tax Form", 50, 20);

        std::cout << bob << std::endl;
        std::cout << tax << std::endl;

        bob.signForm(tax);//Devrait marcher.
        std::cout << tax << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 4 : Bureaucrat trop bas pour signer ----" << std::endl;
    try
    {
        Bureaucrat jim("Jim", 100);
        Form contract("Contract", 20, 20);

        std::cout << jim << std::endl;
        std::cout << contract << std::endl;

        jim.signForm(contract);//Devrait échouer.
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 5 : Formulaire déjà signé ----" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 10);
        Form report("Report", 50, 50);

        alice.signForm(report);//Premier essai OK.
        alice.signForm(report);//Deuxième essai, déjà signé.
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 6 : Plusieurs bureaucrates ----" << std::endl;
    try
    {
        Bureaucrat low("LowGrade", 120);
        Bureaucrat high("HighGrade", 5);
        Form secret("Secret Doc", 10, 10);

        low.signForm(secret);//échoue
        high.signForm(secret);//réussit
        low.signForm(secret);//déjà signé
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    return (0);
}
