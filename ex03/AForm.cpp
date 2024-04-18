/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:04 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/18 08:44:10 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(): name("none"), grade_to_execute(150), grade_to_sign(150)
{
	std::cout << "\033[1;32mDEFAULT AFORM CONSTRUCTOR NONE\033[0m" << std::endl;
	std::cout << "Form named none has been created succesfully" << std::endl;
	this->is_sigend = false;
	return ;
}

AForm::AForm(AForm &to_copy): name(to_copy.name),
	grade_to_execute(to_copy.grade_to_execute), grade_to_sign(to_copy.grade_to_sign)
{
	this->is_sigend = to_copy.is_sigend;
	std::cout << "\033[1;32mAFORM COPY CONSTRUCTOR NONE\033[0m" << std::endl;
	std::cout << "Form " << to_copy.name << "has been succesfully copied" << std::endl;
	return ;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute): name(name),
	grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
		throw AForm::GradeTooHightException();
	this->is_sigend = false;
	std::cout << "\033[1;32mAFORM CONSTRUCTOR\033[0m" << std::endl;
	std::cout << "Form named " << name << " has been successfully created" << std::endl;
	return ;
}

AForm::~AForm()
{
	std::cout << "\033[1;31mAFORM DESTRUCTOR: \033[0m" << std::endl;
    return ;
}

std::string	AForm::get_name() const
{
	return (this->name);
}

bool		AForm::get_status() const
{
	return (this->is_sigend);
}

int			AForm::get_grade_to_sign() const
{
	return (this->grade_to_sign);
}

int			AForm::get_grade_to_execute() const
{
	return (this->grade_to_execute);
}

void		AForm::beSigned(Bureaucrat signatory)
{
	if (this->grade_to_sign < signatory.get_grade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << this->name << " has been signed" << std::endl;
		this->is_sigend = true;
	}
	return ;
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (this->is_sigend == false)
	{
		throw AForm::NotSignedException();
		return ;
	}
	if (this->grade_to_execute >= executor.get_grade())
		this->action();
	else
		std::cout << "\033[1;31mERROR: executor grade too low\033[0m" << std::endl;
	return ;
}

const char *AForm::GradeTooHightException::what() const throw()
{   
    return ((char *)"\033[1;31mError: grade is to hight, the highest grade is 1\033[0m");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ((char *)"\033[1;31mError: grade is to low, cannot sign\033[0m");
}

const char *AForm::NotSignedException::what() const throw()
{   
    return ((char *)"\033[1;31mError: this form is not signed\033[0m");
}

std::ostream& operator<<(std::ostream& os, const AForm &aform)
{
    os << aform.get_name() << std::endl;
    os << "grade to sign: ";
	os << aform.get_grade_to_sign();
	os << ", grade to execute: ";
	os << aform.get_grade_to_execute();
	os << ", status: ";
	os << aform.get_status();
    return (os);
}
