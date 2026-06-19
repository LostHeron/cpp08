/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:21:24 by jweber            #+#    #+#             */
/*   Updated: 2026/06/19 19:31:22 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

Span::Span(unsigned int N)
{
	_data.reserve(N);
}

Span::Span(const Span& other):
	_data(other._data)
{
}

const Span& Span::operator=(const Span& other)
{
	if (&other != this)
	{
		_data = other._data;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int newValue)
{
	if (this->size() == this->capacity())
	{
		throw Span::Full();
	}
	else
	{
		this->_data.push_back(newValue);
	}
}

/*
void	Span::addNumberMultiple(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
	for (std::vector<int>::const_iterator tmp = first; tmp != last; tmp++) 
	{
		this->addNumber(*tmp);
	}
}
*/

unsigned int getSpanBetweenTwoInt(int smaller, int greater);

unsigned int	Span::shortestSpan()
{
	unsigned int min;
	if (this->_data.size() <= 1)
		throw Span::OneElement();

	Span cpy(*this);
	std::sort(cpy._data.begin(), cpy._data.end());
	min = getSpanBetweenTwoInt(cpy.at(0), cpy.at(1));
	for (size_t i = 1; i < cpy.size() - 1; i++)
	{
		unsigned int tmp = getSpanBetweenTwoInt(cpy.at(i), cpy.at(i + 1));
		if (tmp < min)
			min = tmp;
	}
	return (min);
}

unsigned int	Span::longestSpan()
{
	if (this->_data.size() <= 1)
		throw Span::OneElement();

	Span cpy(*this);

	std::sort(cpy._data.begin(), cpy._data.end());

	return ( getSpanBetweenTwoInt(cpy.at(0), cpy.at(cpy.size() - 1)) );
}


unsigned int getSpanBetweenTwoInt(int smaller, int greater)
{
	/*
	if (smaller > greater)
		throw Span::
	*/
	unsigned int a;
	unsigned int b;
	if (greater < 0)
	{
		a = - smaller;
		b = - greater;
		return (a - b);
	}
	else if (smaller < 0)
	{
		a = - smaller;
		b = greater;
		return (b + a);
	}
	else
	{
		a = smaller;
		b = greater;
		return (b - a);
	}
}

unsigned int	Span::capacity() const
{
	return (this->_data.capacity());
}

unsigned int 	Span::size() const
{
	return (this->_data.size());
}

const char * Span::Full::what() const throw()
{
	return ("Span is full");
}

const char * Span::OneElement::what() const throw()
{
	return ("Span do not contains enough elements!");
}

const int&		Span::at(unsigned int i) const
{
	return (this->_data.at(i));
}

int&			Span::at(unsigned int i)
{
	return (this->_data.at(i));
}

std::ostream&	operator<<(std::ostream& os, const Span& span)
{
	os << "Span(" << span.size() << "/" << span.capacity() << "): ";
	unsigned int i;
	for (i = 0; i < span.size() && i < 50; i++)
	{
		if (i != 0)
			os << ", ";
		os << span.at(i);
	}
	if (!(i < 50))
		std::cout << "...";
	return (os);
}

