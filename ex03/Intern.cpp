/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 07:11:59 by francesco         #+#    #+#             */
/*   Updated: 2024/04/18 08:51:29 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "\033[1;32mDEFAULT INTERN CONSTRUCTOR\033[0m" << std::endl;
}

Intern::~Intern()
{
    std::cout << "\033[1;31mINTERN DESTRUCTOR: \033[0m" << std::endl;
}

Intern::Intern(Intern &to_copy)
{
    (void)to_copy;
    std::cout << "\033[1;32mINTERN COPY CONSTRUCTOR\033[0m" << std::endl;
}
        
Intern &Intern::operator=(Intern const &to_copy)
{
    std::cout << "\033[1;32mINTERN COPY OVERLOAD\033[0m" << std::endl;
    return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int         i;
    
    i = 1;
    while (i < 3)
    {
        if (form_name == forms[i])
            break;
        i++;
    }
    switch (i)
    {
        case 1:
        {
            return (new PresidentialPardonForm(target));
            break;
        }
        case 2:
        {
            return (new RobotomyRequestForm(target));
            break;
        }
        case 3:
        {
            return (new ShrubberyCreationForm(target));
            break;
        }
        default:
            std::cout << "\033[1;31mERROR: incorect form name\033[0m" << std::endl;
    }
    return NULL;
}