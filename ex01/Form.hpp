/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:43:15 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/15 13:57:39 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const	int			grade_to_sign;
		const	int			grade_to_execute;
	public:
		Form();
		Form(Form &to_copy);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		~Form();
		Form	&operator=(Form &to_copy);
		std::string	get_name() const;
		bool		get_status() const;
		int			get_grade_to_sign() const;
		int			get_grade_to_execute() const;
		void		beSigned(Bureaucrat signatory);
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
		class GradeTooLowExceptionSign : public std::exception
        {
            public:
                const char *what() const throw ();
        };
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

# endif