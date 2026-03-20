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
#include <vector>
#include <iostream>
#include <iterator>

int	main(int argc, char **argv)
{
	std::stringstream	ss;
	int					searched;

	if (argc != 2)
	{
		std::cout << "usage: ./a.out value_to_search\n";
		return (1);
	}
	ss << argv[1];
	ss >> searched;
	if (ss.fail())
	{
		std::cout << "could not convert '" << argv[1] << "' to type int\n";
		return (1);
	}

	std::vector<int> v;
	v.reserve(5);
	for (int i = 1; i <= 5; i++)
	{
		v.push_back(i * 10);
	}

	std::vector<int>::const_iterator it = ::easyfind(v, searched);
	std::cout << "value " << searched;
	if (it != v.end())
		std::cout << " was found\n";
	else
		std::cout << " was NOT found\n";
}
