/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:43:15 by ftholoza          #+#    #+#             */
/*   Updated: 2024/04/17 19:56:09 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
	private:
        std::string         target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm &to_copy);
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();
        void        action() const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &Robotomy);

# endif