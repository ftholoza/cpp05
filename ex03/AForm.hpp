/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:43:15 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/27 15:44:21 by ftholoza         ###   ########.fr       */
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
		bool				is_signed;
		const	int			grade_to_sign;
		const	int			grade_to_execute;
	public:
		AForm();
		AForm(AForm &to_copy);
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		~AForm();
		
		AForm	&operator=(AForm &to_copy);
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
		class GradeTooLowExceptionSign : public std::exception
		{
			public:
				const char *what() const throw ();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

# endif