/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:51:21 by jweber            #+#    #+#             */
/*   Updated: 2026/03/06 16:46:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <iterator>
template<typename T>
typename T::const_iterator	easyfind(const T& ref, int value)
{
	typename T::const_iterator	it;
	for (it = ref.begin(); it != ref.end(); it++)
	{
		if (*it == value)
			return (it);
	}
	return (it);
}

#endif
