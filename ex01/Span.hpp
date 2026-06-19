/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:02:24 by jweber            #+#    #+#             */
/*   Updated: 2026/06/19 19:20:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <cstdlib>
# include <exception>
#include <ostream>
#include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span& other);
		const Span& operator=(const Span& other);
		~Span();

		unsigned int	capacity() const;
		unsigned int 	size() const;
		const int&		at(unsigned int i) const;
		int&			at(unsigned int i);

		void			addNumber(int newValue);

		template< class InputIt >
		void			addNumberMultiple(InputIt first, InputIt last);

		//void			addNumberMultiple(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);

		unsigned int	longestSpan();
		unsigned int	shortestSpan();

	class Full: public std::exception
	{
		public:
			const char * what() const throw();
	};

	class OneElement: public std::exception
	{
		public:
			const char * what() const throw();
	};

	private:
		Span();

		std::vector<int>	_data;
};

std::ostream&	operator<<(std::ostream& os, const Span& span);

#include "Span.tpp"

#endif
