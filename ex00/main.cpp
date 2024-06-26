/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:43 by francesco         #+#    #+#             */
/*   Updated: 2024/05/27 15:29:09 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{   
    try
    {
        std::cout << "try to create bureaucrat of grade 0" << std::endl;
        Bureaucrat b("Pascal", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "try to create bureaucrat of grade -100" << std::endl;
        Bureaucrat b("Pascal", -100);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "try to create bureaucrat of grade 160" << std::endl;
        Bureaucrat d("Patrice", 160);
        std::cout << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "try to create bureaucrat of grade 999999" << std::endl;
        Bureaucrat c("Pierre", 999999);
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "try to increment bureaucrat from 150 to 1" << std::endl;
        Bureaucrat d("Paul", 150);
        std::cout << d << std::endl;
        for (int i = 0; i < 149; i++)
            d.increment();
        std::cout << d << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "try to decrement bureaucrat from 1 to 150" << std::endl;
        Bureaucrat d("Paul", 1);
        std::cout << d << std::endl;
        for (int i = 0; i < 149; i++)
            d.decrement();
        std::cout << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "try to create bureaucrat of grade -1" << std::endl;
        Bureaucrat e("Pierrique", -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "try to decrement bureaucrat under 150" << std::endl;
        Bureaucrat  f("test", 150);
        f.decrement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "try to increment bureaucrat upper 1" << std::endl;
        Bureaucrat  f("test", 1);
        f.increment();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "orthodox tests" << std::endl;
        Bureaucrat  f("james", 1);
        Bureaucrat  g(f);
        std::cout << f << std::endl;
        std::cout << g << std::endl;
        std::cout << "decrement g" << std::endl;
        g.decrement();
        std::cout << g << std::endl;
        std::cout << "copy overload f = g" << std::endl;
        f = g;
        std::cout << f << std::endl;
        std::cout << g << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}