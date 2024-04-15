/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 07:08:55 by francesco         #+#    #+#             */
/*   Updated: 2024/04/06 10:11:35 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
        throw Bureaucrat::GradeTooHightException(grade);
    if (grade > 155)
        throw Bureaucrat::GradeTooLowException(grade);
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

int Bureaucrat::GradeTooHightException(int  nb)
{
    return (nb);
}

int Bureaucrat::GradeTooLowException(int nb)
{
    return (nb);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.get_name();
    os << ", bureaucrat grade ";
    os << bureaucrat.get_grade();
    return (os);
}