/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:43 by francesco         #+#    #+#             */
/*   Updated: 2024/05/27 17:12:12 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    AForm   *test;
    AForm   *test2;
    AForm   *test3;
    std::cout << "---CONSTRUCTORS---" << std::endl;
    ShrubberyCreationForm   shruberry("plop");
    RobotomyRequestForm     robotomy("mail");
    PresidentialPardonForm  presidential("prisonner");
    Bureaucrat              president("President", 1);
    Bureaucrat              stagiaire("stagiaire", 150);
    Bureaucrat              responsable("responsable", 75);
    Intern                  intern;
    std::cout << "---here the intern---" << std::endl;
    test2 = intern.makeForm("robotomy request", "erreert");
    std::cout << *test2 << std::endl;
    delete test2;
    test3 = intern.makeForm("presidential pardon", "business man");
    std::cout << *test3 << std::endl;
    delete test3;
    test = intern.makeForm("shrubbery creation", "home");
    std::cout << *test << std::endl;
    delete  test;
    std::cout << "bad intern" << std::endl;
    test2 = intern.makeForm("", "target");
    std::cout << "return value: " << test2 << std::endl;
    test2 = intern.makeForm("rggerg", "target");
    test2 = intern.makeForm("robotomy request", "");
    test2 = intern.makeForm("presidential pardon", "     ");
    test2 = intern.makeForm("robotomy request", "target");
    std::cout << "----------------------" << std::endl;
    try{
        test2->beSigned(president);
        president.signForm(*test2);
        president.executeForm(*test2);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what();
    }
    delete test2;
    std::cout << "---Destructor---" << std::endl;
}