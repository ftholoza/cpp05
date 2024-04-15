/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 07:09:01 by francesco         #+#    #+#             */
/*   Updated: 2024/04/05 18:11:13 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
        Bureaucrat &operator=(Bureaucrat &to_copy);
        std::string get_name() const;
        int get_grade() const;
        int GradeTooHightException(int nb);
        int GradeTooLowException(int nb);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat);

# endif
