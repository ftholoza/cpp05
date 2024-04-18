/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:43:15 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/17 19:58:52 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				is_sigend;
		const	int			grade_to_sign;
		const	int			grade_to_execute;
	public:
		AForm();
		AForm(AForm &to_copy);
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		~AForm();
		std::string	get_name() const;
		bool			get_status() const;
		int				get_grade_to_sign() const;
		int				get_grade_to_execute() const;
		void			beSigned(Bureaucrat signatory);
		virtual void	execute(Bureaucrat const & executor) const;
		virtual void	action() const = 0;
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
		class NotSignedException : public std::exception
        {
            public:
                const char *what() const throw ();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

# endif