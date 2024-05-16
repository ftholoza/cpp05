/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:43 by francesco         #+#    #+#             */
/*   Updated: 2024/05/15 10:40:37 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "\033[1;32m-----CONSTRUCTORS----\033[0m" << std::endl;
    Form a();
    Form b("exclusivity pact", 1, 1);
    Form c("cofee machine", 150, 150);
    Bureaucrat d("Bernard", 1);
    Bureaucrat e("Sebastien", 150);
    std::cout << "\033[1;32m---------------------\033[0m" << std::endl;
    std::cout << "orthodox tests" << std::endl;
    try
    {
        Form test("formulaire", 1, 1);
        test.beSigned(d);
        Form copy(test);
        std::cout << test << std::endl;
        std::cout << copy << std::endl;
        Form test2("paper", 150, 150);
        std::cout << "test = test2" << std::endl;
        test = test2;
        std::cout << test << std::endl;
        std::cout << test2 << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "test exclusivity pact sign by Sebastien" << std::endl;
        std::cout << b << std::endl;
        std::cout << e << std::endl;
        b.beSigned(e);
        e.signForm(b);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "test exclusivity pact sign by Bernard" << std::endl;
        std::cout << b << std::endl;
        std::cout << d << std::endl;
        b.beSigned(d);
        d.signForm(b);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat  f("constantin", 3);
        Form        g("sale of share", 2, 2);
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