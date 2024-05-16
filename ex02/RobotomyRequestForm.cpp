/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:04 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/15 14:07:29 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
# include <cstdlib>
# include <stdlib.h>
# include <ctime>
# include <iostream>


RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45)
{
	this->target = "none";
	std::cout << "\033[1;32mDEFAULT FORM CONSTRUCTOR NONE\033[0m" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &to_copy): AForm(to_copy)
{
	std::cout << "\033[1;32mFORM COPY CONSTRUCTOR NONE\033[0m" << std::endl;
	this->target = to_copy.target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45), target(target)
{
	std::cout << "\033[1;32mFORM CONSTRUCTOR\033[0m" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[1;31mFORM DESTRUCTOR: \033[0m" << std::endl;
    return ;
}

void		RobotomyRequestForm::action() const
{
    std::srand(std::time(NULL));
    if ((std::rand() % 100) >= 50)
    {
        std::cout << "BipBip" << std::endl;
        std::cout << this->target << "has been robotomized" << std::endl;
    }
    else
        std::cout << "Robotomy failed" << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm &form)
{
    os << form.get_name() << std::endl;
    os << "grade to sign: ";
	os << form.get_grade_to_sign();
	os << ", grade to execute: ";
	os << form.get_grade_to_execute();
	os << ", status: ";
	os << form.get_status();
    return (os);
}