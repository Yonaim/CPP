#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat master("master", Bureaucrat::highest_grade);
        Bureaucrat slave("slave", Bureaucrat::lowest_grade);
		Form i_doc("important_doc", 1, 5);
		Form uni_doc("unimportant_doc", 150, 100);

		std::cout << i_doc << std::endl; 
		std::cout << uni_doc << std::endl;

		// i_doc.beSigned(slave);
		// i_doc.beSigned(master);

		// uni_doc.beSigned(slave);
		// uni_doc.beSigned(master);

		slave.signForm(i_doc);
		slave.signForm(uni_doc);
		master.signForm(i_doc);
		master.signForm(uni_doc);
		std::cout << '\n'; 

		std::cout << i_doc << std::endl; 
		std::cout << uni_doc << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
