/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 07:03:38 by francesco         #+#    #+#             */
/*   Updated: 2024/04/18 08:06:50 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "iostream"

class AForm;

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern &to_copy);
        Intern &operator=(Intern const &to_copy);
        AForm *makeForm(std::string form_name, std::string target);
};

#endif
