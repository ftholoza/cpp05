/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:43 by francesco         #+#    #+#             */
/*   Updated: 2024/04/15 13:50:35 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    std::cout << "\033[1;32m-----CONSTRUCTORS----\033[0m" << std::endl;
    Form a();
    Form b("exclusivity pact", 1, 1);
    Form c("cofee machine", 150, 150);
    Bureaucrat d("Bernard", 1);
    Bureaucrat e("Sebastien", 150);
    std::cout << "\033[1;32m---------------------\033[0m" << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    try
    {
        b.beSigned(e);
        e.signForm(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        b.beSigned(d);
        d.signForm(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat  f("constantin", 3);
        Form        g("sale of share", 2, 2);
        g.beSigned(f);
        f.signForm(g);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat  f("constantin", 3);
        Form        g("sale of share", 2, 2);
        f.increment();
        g.beSigned(f);
        f.signForm(g);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}