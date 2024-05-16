/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:43:15 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/15 14:09:11 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONAFORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm
{
	private:
        std::string   target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &to_copy);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
        void                action() const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &presidential);

# endif