/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 07:46:06 by jweber            #+#    #+#             */
/*   Updated: 2026/06/23 08:59:29 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template<typename _Type, typename _Container=std::deque<_Type> >
class MutantStack: public std::stack<_Type, _Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		const MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		typedef typename _Container::iterator iterator;

		iterator begin();
		iterator end();
};

template<typename _Type, typename _Container >
MutantStack<_Type, _Container>::MutantStack():
	std::stack<_Type, _Container>()
{
}

template<typename _Type, typename _Container >
MutantStack<_Type, _Container>::MutantStack(const MutantStack& other):
	std::stack<_Type, _Container>(other)
{
}

template<typename _Type, typename _Container >
const MutantStack<_Type, _Container>&	MutantStack<_Type, _Container>::operator=(const MutantStack<_Type, _Container>& other)
{
	this->std::stack<_Type, _Container>::operator=(other);
	return (*this);
}

template<typename _Type, typename _Container >
MutantStack<_Type, _Container>::~MutantStack()
{
}

template<typename _Type, typename _Container >
typename MutantStack<_Type, _Container>::iterator MutantStack<_Type, _Container>::begin()
{
	return (this->c.begin());
}

template<typename _Type, typename _Container >
// i do not get the point of the 'typename' just below
// but apparently it is to tell the compiler to parse things differently
// when calling YO<T>::x we might not be in scope correct scope yet, and so the
// 'typename' is required, but i do not fully get it yet
// because the compiler does not know if YO<T>::x is a type or a static member variable
// 'typename' explicitly tells the compiler that YO<T>::x is a type
typename MutantStack<_Type, _Container>::iterator MutantStack<_Type, _Container>::end()
{
	return (this->c.end());
}

#endif
