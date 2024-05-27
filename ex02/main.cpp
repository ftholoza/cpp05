/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:43 by francesco         #+#    #+#             */
/*   Updated: 2024/05/27 17:13:29 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    std::cout << "---CONSTRUCTORS---" << std::endl;
    ShrubberyCreationForm   shruberry("plop");
    RobotomyRequestForm     robotomy("mail");
    PresidentialPardonForm  presidential("prisonner");
    Bureaucrat              president("President", 1);
    Bureaucrat              stagiaire("stagiaire", 150);
    Bureaucrat              responsable("responsable", 75);
    std::cout << "----------------" << std::endl;
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
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        president.executeForm(presidential);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        president.executeForm(robotomy); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---tests with responsable---" << std::endl;
    try
    {
        responsable.executeForm(robotomy);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        responsable.executeForm(shruberry);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        responsable.executeForm(presidential);
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
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << responsable << std::endl;
    std::cout << "---Destructor---" << std::endl;
}