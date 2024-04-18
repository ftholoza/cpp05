/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:43:15 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/17 19:56:14 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
        std::string         target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &to_copy);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
        void        action() const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &Shrubbery);

# endif