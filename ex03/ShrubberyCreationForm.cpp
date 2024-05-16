/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:04 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/15 14:23:45 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{
	std::cout << "\033[1;32mDEFAULT FORM CONSTRUCTOR NONE\033[0m" << std::endl;
	this->target = "none";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shruberry", 145, 137)
{
	std::cout << "\033[1;32mDEFAULT FORM CONSTRUCTOR\033[0m" << std::endl;
	this->target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &to_copy): AForm(to_copy)
{
	std::cout << "\033[1;32mFORM COPY CONSTRUCTOR NONE\033[0m" << std::endl;
	this->target = to_copy.target;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[1;31mFORM DESTRUCTOR: \033[0m" << std::endl;
    return ;
}

void		ShrubberyCreationForm::action() const
{
	if (this->get_status() == true)
	{
		std::ofstream out((this->target + "_shrubbery").c_str());
		if (out.is_open())
		{
			out << " ... ................++*............. .." << std::endl;
			out << "......... ........++++++++..-:.....  ..." << std::endl;
 			out << "... ..... .....=++++++++++=++.... .. .." << std::endl;
			out << ".............============-==.......  ..." << std::endl;
			out << "...........=============-.==:==........." << std::endl;
 			out << "... .......----.-*:.*+------........ .. " << std::endl;
			out << ".. ........=*++++=--#-=---+=:......  .. " << std::endl; 
			out << ". .. ......===*===---*-=-------+:......." << std::endl; 
			out << ".....+++*-..:-----++#=-------+++++++...." << std::endl; 
			out << "..:+++++++++-------#+-----=++++++++++:+." << std::endl; 
			out << ".===========----+---*=-===========+==.=." << std::endl; 
			out << ".======:+...-=-#=---#===-.=====-==--==-." << std::endl; 
			out << ".::-:-=.-:**...+.:..:-#-----=---.------." << std::endl; 
			out << "..............:#...#*##*#=......:..*...." << std::endl; 
			out << "... ............ ...###... .. ...... .. " << std::endl; 
			out << ".. ......... .. .....***................" << std::endl; 
			out << ".... .. .. ... .....:**%...... ........." << std::endl; 
			out << "......... ........ .**#+. ...... ..  ..." << std::endl; 
			out << ".... ..... ... .....###*.......... ....." << std::endl; 
			out << "......... ........-##*#*#%:........  .. " << std::endl; 
			out << ".................:.**+...#..::.........." << std::endl;
			out.close();
		}
	}
	else
		std::cout << "\033[1;31mERROR: executor grade too low\033[0m" << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm &form)
{
    os << form.get_name() << std::endl;
    os << "grade to sign: ";
	os << form.get_grade_to_sign();
	os << ", grade to execute: ";
	os << form.get_grade_to_execute();
	os << ", status: ";
	os << form.get_status();
    return (os);
}