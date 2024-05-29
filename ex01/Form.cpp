/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:04 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 20:38:56 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(): name("none"), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "\033[1;32mDEFAULT FORM CONSTRUCTOR NONE\033[0m" << std::endl;
	this->is_signed = false;
	return ;
}

Form::Form(Form &to_copy): name(to_copy.name),
	is_signed(to_copy.is_signed), grade_to_sign(to_copy.grade_to_sign), grade_to_execute(to_copy.grade_to_execute)
{
	this->is_signed = to_copy.is_signed;
	std::cout << "\033[1;32mFORM COPY CONSTRUCTOR NONE\033[0m" << std::endl;
	return ;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute): name(name),
	grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
		throw Form::GradeTooLowException();
	if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
		throw Form::GradeTooHightException();
	this->is_signed = false;
	std::cout << "\033[1;32mFORM CONSTRUCTOR\033[0m" << std::endl;
	return ;
}

Form&	Form::operator=(Form &to_copy)
{
	(void)to_copy;
	std::cout << "COPY OPERATOR OVERLOAD CANT COPY" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "\033[1;31mFORM DESTRUCTOR: \033[0m" << std::endl;
    return ;
}

std::string	Form::get_name() const
{
	return (this->name);
}

bool		Form::get_status() const
{
	return (this->is_signed);
}

int			Form::get_grade_to_sign() const
{
	return (this->grade_to_sign);
}

int			Form::get_grade_to_execute() const
{
	return (this->grade_to_execute);
}

void		Form::beSigned(Bureaucrat signatory)
{
	if (this->grade_to_sign < signatory.get_grade())
		throw Form::GradeTooLowExceptionSign();
	else
		this->is_signed = true;
	return ;
}

const char *Form::GradeTooHightException::what() const throw()
{   
    return ((char *)"\033[1;31mError: grade is to hight, the highest grade is 1\033[0m");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ((char *)"\033[1;31mError: grade is to low, the lowest grade is 150\033[0m");
}

const char *Form::GradeTooLowExceptionSign::what() const throw()
{
	return ((char *)"\033[1;31mError: grade is to low, cannot sign\033[0m");
}

std::ostream& operator<<(std::ostream& os, const Form &form)
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
