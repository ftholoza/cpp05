/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:04 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 20:43:18 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(): name("none"), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "\033[1;32mDEFAULT AFORM CONSTRUCTOR NONE\033[0m" << std::endl;
	this->is_signed = false;
	return ;
}

AForm::AForm(AForm &to_copy): name(to_copy.name),
	is_signed(to_copy.is_signed), grade_to_sign(to_copy.grade_to_sign), grade_to_execute(to_copy.grade_to_execute)
{
	this->is_signed = to_copy.is_signed;
	std::cout << "\033[1;32mAFORM COPY CONSTRUCTOR NONE\033[0m" << std::endl;
	return ;
}

AForm&	AForm::operator=(AForm &to_copy)
{
	(void)to_copy;
	std::cout << "COPY OPERATOR OVERLOAD CANT COPY" << std::endl;
	return (*this);
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute): name(name),
	grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
		throw AForm::GradeTooHightException();
	this->is_signed = false;
	std::cout << "\033[1;32mAFORM CONSTRUCTOR\033[0m" << std::endl;
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
	return (this->is_signed);
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
		throw AForm::GradeTooLowExceptionSign();
	else
	{
		this->is_signed = true;
	}
	return ;
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (this->is_signed == false)
	{
		throw AForm::NotSignedException();
		return ;
	}
	if (this->grade_to_execute >= executor.get_grade())
		this->action();
	else
	{
		throw AForm::GradeTooLowException();
		return ;
	}
	return ;
}

const char *AForm::GradeTooHightException::what() const throw()
{   
    return ("\033[1;31mError: grade is to hight, the highest grade is 1\033[0m");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("\033[1;31mError: grade is to low, cannot sign\033[0m");
}

const char *AForm::NotSignedException::what() const throw()
{   
    return ("\033[1;31mError: this form is not signed\033[0m");
}

const char *AForm::GradeTooLowExceptionSign::what() const throw()
{
	return ("\033[1;31mError: grade is to low, cannot sign\033[0m");
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
