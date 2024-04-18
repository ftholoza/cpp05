/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 07:09:01 by francesco         #+#    #+#             */
/*   Updated: 2024/04/17 20:47:30 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat &to_copy);
        Bureaucrat  &operator=(Bureaucrat &to_copy);
        std::string get_name() const;
        int         get_grade() const;
        void        increment();
        void        decrement();
        void        signForm(AForm &form);
        void        executeForm(AForm const & form);
        class GradeTooHightException : public std::exception
        {
            public:
                const char *what() const throw ();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw ();
        };
        class GradeTooHightExceptionSign : public std::exception
        {
            public:
                const char *what() const throw ();
        };
        class GradeTooLowExceptionSign : public std::exception
        {
            public:
                const char *what() const throw ();
        };
        class GradeTooHightExceptionExec : public std::exception
        {
            public:
                const char *what() const throw ();
        };
        class GradeTooLowExceptionExec : public std::exception
        {
            public:
                const char *what() const throw ();
        };
        class NotSignedException : public std::exception
        {
            public:
                const char *what() const throw ();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat);

# endif
