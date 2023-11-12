#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", Bureaucrat::highest_grade);
        Bureaucrat b2("b2", 100);
        Bureaucrat b3("b3", Bureaucrat::lowest_grade);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        // Bureaucrat e1("exception1", Bureaucrat::highest_grade - 1);
        // Bureaucrat e2("exception2", Bureaucrat::lowest_grade + 1);
		// 위에서 exception 던져질시 실행되지 않는다

        std::cout << b3 << std::endl;
		// 위에서 exception 던져질시 실행되지 않는다
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Bureaucrat e1("exception1", 0); // uncaught exception
    // Bureaucrat e2("exception2", 151); // uncaught exception

	std::cout << '\n'; 

    try
    {
        Bureaucrat g1("g1", Bureaucrat::highest_grade);
        Bureaucrat g2("g2", 100);
        Bureaucrat g3("g3", Bureaucrat::lowest_grade);

        g2.incrementGrade();
        std::cout << g2 << std::endl;
        g2.decrementGrade();
        std::cout << g2 << std::endl;

        // g1.incrementGrade(); // exception
        // g3.decrementGrade(); // exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
