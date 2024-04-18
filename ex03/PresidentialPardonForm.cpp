/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:04 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/17 18:59:18 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5)
{
	std::cout << "\033[1;32mDEFAULT FORM CONSTRUCTOR NONE\033[0m" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &to_copy): AForm(to_copy)
{
	std::cout << "\033[1;32mFORM COPY CONSTRUCTOR NONE\033[0m" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential", 25, 5), target(target)
{
	std::cout << "\033[1;32mPRESIDENTIAL CONSTRUCTOR\033[0m" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[1;31mFORM DESTRUCTOR: \033[0m" << std::endl;
    return ;
}

void		PresidentialPardonForm::action() const
{
	if (this->get_status() == true)
    {
        std::cout << this->target << " has been pardoned by Zaohid Reeblebrox" << std::endl;
    }
	else
		std::cout << "\033[1;31mERROR: executor grade too low\033[0m" << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm &form)
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
