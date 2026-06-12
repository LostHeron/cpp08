/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:05:12 by jweber            #+#    #+#             */
/*   Updated: 2026/03/06 16:10:55 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

int	main(void)
{

	{
		std::vector<int> v;
		v.reserve(5);
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);

		std::cout << "~~~~~~~~~~~~ vector of int : ~~~~~~~~~~~~~\n";
		for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
		{
			std::cout << *it << "\n";
		}
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			
		std::vector<int>::const_iterator it;
		int		searched;

		searched = 10;
		it = ::easyfind(v, searched);
		std::cout << "value searched : '" << searched << "':\n";
		if (it != v.end())
			std::cout << "found\n";
		else
			std::cout << "NOT found\n";

		searched = 11;
		std::cout << "value searched : '" << searched << "':\n";
		it = ::easyfind(v, searched);
		if (it != v.end())
			std::cout << "found\n";
		else
			std::cout << "NOT found\n";
	}

	std::cout << "\n\n\n";

	{
		std::vector<std::string> v;
		v.reserve(5);
		v.push_back("coucou");
		v.push_back("salut");
		v.push_back("bonjour");

		std::cout << "~~~~~~~~~~~~ vector of string : ~~~~~~~~~~~~~\n";
		for (std::vector<std::string>::const_iterator it = v.begin(); it != v.end(); it++)
		{
			std::cout << *it << "\n";
		}
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			
		std::vector<std::string>::const_iterator it;
		std::string			searched;

		searched = "coucou";
		it = ::easyfind(v, searched);
		std::cout << "value searched : '" << searched << "':\n";
		if (it != v.end())
			std::cout << "found\n";
		else
			std::cout << "NOT found\n";

		searched = "ahah";
		std::cout << "value searched : '" << searched << "':\n";
		it = ::easyfind(v, searched);
		if (it != v.end())
			std::cout << "found\n";
		else
			std::cout << "NOT found\n";
	}
}
