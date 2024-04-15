/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:43:15 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/15 13:53:13 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_sigend;
		const	int			grade_to_sign;
		const	int			grade_to_execute;
	public:
		Form();
		Form(Form &to_copy);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		~Form();
		std::string	get_name() const;
		bool		get_status() const;
		int			get_grade_to_sign() const;
		int			get_grade_to_execute() const;
		virtual void		beSigned(Bureaucrat signatory);
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
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

# endif