/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:21:24 by jweber            #+#    #+#             */
/*   Updated: 2026/06/12 18:02:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
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

void	Span::addNumber(ssize_t newValue)
{
	if (this->_data.size() == this->_data.capacity())
	{
		throw Span::Full();
	}
	else
	{
		this->_data.push_back(newValue);
	}
}

unsigned int	Span::shortestSpan()
{
	/*
	if (this->_data.size() <= 1)

		throw Span::OneElement();
	std::vector<int> cpy = this->_data;
	*/
	return (3);
}

unsigned int	Span::longestSpan()
{
	if (this->_data.size() <= 1)
		throw Span::OneElement();
	std::vector<int> cpy = this->_data;
	std::sort(this->_data.begin(), this->_data.end());

	unsigned int a;
	unsigned int b;
	if (this->_data.at(0) < 0 && this->_data.at(this->_data.size() - 1) < 0)
	{
		a = - _data.at(0);
		b = - _data.at(this->_data.size() - 1);
	}
	else if (this->_data.at(this->_data.size() - 1) < 0)
	{
		a = - _data.at(0);
		b = _data.at(this->_data.size() - 1);
	}
	else
	{
		a = _data.at(0);
		b = _data.at(this->_data.size() - 1);
	}
	return (b - a);
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
	for (unsigned int i = 0; i < span.size(); i++)
	{
		if (i != 0)
			os << ", ";
		os << span.at(i);
	}
	return (os);
}

