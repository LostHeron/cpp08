/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:19:41 by jweber            #+#    #+#             */
/*   Updated: 2026/06/12 18:02:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>
#include <limits>

int	main(void)
{
	try 
	{
		Span a(3);
		std::cout << "a = " << a << "\n";
		a.addNumber(std::numeric_limits<int>::max());
		a.addNumber(std::numeric_limits<int>::min());
		a.addNumber(5);
		std::cout << "a = " << a << "\n";
		std::cout << a.longestSpan() << "\n";

		Span b(a);
		std::cout << "b = " << b << "\n";
		Span c(0);
		c = a;
		std::cout << "c = " << c << "\n";
		a.addNumber(6);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}
