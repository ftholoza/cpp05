/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 07:08:55 by francesco         #+#    #+#             */
/*   Updated: 2024/05/27 17:11:58 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::~Bureaucrat()
{
    	std::cout << "\033[1;31mBUREACRAT DESTRUCTOR: \033[0m" << std::endl;
        return ;
}

Bureaucrat::Bureaucrat(): _name("none")
{
    std::cout << "\033[1;32mDEFAULT BUREAUCRAT CONSTRUCTOR NONE\033[0m" << std::endl;
    this->_grade = 150;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout << "\033[1;32mBUREAUCRAT CONSTRUCTOR\033[0m" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHightException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat &to_copy): _name(to_copy._name)
{
    std::cout << "\033[1;32mBUREAUCRAT COPY CONSTRUCTOR\033[0m" << std::endl;
    this->_grade = to_copy._grade;
    return ;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &to_copy)
{
    std::cout << "Bureaucrat copy" << std::endl;
    this->_grade = to_copy._grade;
    return (*this);
}

std::string Bureaucrat::get_name() const
{
    return (this->_name);
}

int Bureaucrat::get_grade() const
{
    return (this->_grade);
}

void    Bureaucrat::increment()
{
    if (this->get_grade() <= 1)
        throw Bureaucrat::GradeTooHightException();
    else
        this->_grade--;
    return ;
}

void    Bureaucrat::decrement()
{
    if (this->get_grade() >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
    return ;
}

void    Bureaucrat::signForm(AForm &form)
{
    if (form.get_grade_to_sign() < this->get_grade())
    {
        std::cout << this->get_name() << " couldn't sign " << form.get_name() << " because his grade is to low" << std::endl;
    }
    else
        std::cout << this->_name << " signed " << form.get_name() << std::endl;
}

void    Bureaucrat::executeForm(AForm const & form)
{
    if (form.get_status() == false)
	{
		std::cout << this->_name << " couldn't execute " << form.get_name() << " because form not signed" << std::endl;
		return ;
	}
	if (form.get_grade_to_execute() >= this->get_grade())
    {
        form.execute(*this);
		std::cout << this->_name << " execute " << form.get_name() << std::endl;
    }
	else
        std::cout << this->_name << " couldn't execute " << form.get_name() << " because grade is too low" << std::endl;
	return ;
}

const char *Bureaucrat::NotSignedException::what() const throw()
{   
    return ((char *)"\033[1;31mError: this form is not signed\033[0m");
}

const char *Bureaucrat::GradeTooLowExceptionSign::what() const throw()
{
    return ((char *)"\033[1;31mError: grade is to low to sign\033[0m");
}

const char *Bureaucrat::GradeTooHightException::what() const throw()
{   
    return ((char *)"\033[1;31mError: grade is to hight, the highest grade is 1\033[0m");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ((char *)"\033[1;31mError: grade is to low, the lowest grade is 150\033[0m");
}

const char *Bureaucrat::GradeTooLowExceptionExec::what() const throw()
{
    return ((char *)"\033[1;31mError: grade is to low to exec\033[0m");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.get_name();
    os << ", bureaucrat grade ";
    os << bureaucrat.get_grade();
    return (os);
}