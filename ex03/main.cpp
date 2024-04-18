/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:43 by francesco         #+#    #+#             */
/*   Updated: 2024/04/18 09:07:00 by francesco        ###   ########.fr       */
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
    std::cout << "---CONSTRUCTORS---" << std::endl;
    ShrubberyCreationForm   shruberry("plop");
    RobotomyRequestForm     robotomy("mail");
    PresidentialPardonForm  presidential("prisonner");
    Bureaucrat              president("President", 1);
    Bureaucrat              stagiaire("stagiaire", 150);
    Bureaucrat              responsable("responsable", 75);
    Intern                  intern;
    std::cout << "---here the intern---" << std::endl;
    test = intern.makeForm("shrubbery creation", "home");
    std::cout << *test << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "---BASIC-TESTS---" << std::endl;
    std::cout << "stagiaire tests sign forms" << std::endl;
    try
    {
        stagiaire.signForm(shruberry);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        stagiaire.signForm(robotomy);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        stagiaire.signForm(presidential);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "stagiaire test exec form -form aleready signed-" << std::endl;
    try
    {
        shruberry.beSigned(president);
        stagiaire.executeForm(shruberry);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        robotomy.beSigned(president);
        stagiaire.executeForm(robotomy);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        presidential.beSigned(president);
        stagiaire.executeForm(presidential);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---test president execute all the forms---" << std::endl;
    try
    {
        president.executeForm(shruberry);
        shruberry.execute(president);   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        president.executeForm(presidential);
        presidential.execute(president);   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        president.executeForm(robotomy);
        robotomy.execute(president);   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---tests with responsable---" << std::endl;
    try
    {
        responsable.executeForm(robotomy);
        robotomy.execute(responsable);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        responsable.executeForm(shruberry);
        shruberry.execute(responsable);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        responsable.executeForm(presidential);
        presidential.execute(responsable);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "---increment responsable grade x10---" << std::endl;
    for (int i = 0; i < 10; i++)
        responsable.increment();
    std::cout << responsable << std::endl;
    try
    {
        responsable.executeForm(presidential);
        presidential.execute(responsable);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "---increment responsable grade x60---" << std::endl;
    for (int i = 0; i < 60; i++)
        responsable.increment();
    try
    {
        responsable.executeForm(presidential);
        presidential.execute(responsable);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << responsable << std::endl;
    std::cout << "---Destructor---" << std::endl;
}