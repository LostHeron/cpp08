/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 08:08:39 by jweber            #+#    #+#             */
/*   Updated: 2026/06/23 08:45:48 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <vector>

int	main(void)
{
	MutantStack<int, std::vector<int> > a;
	a.push(30);
	a.push(20);
	a.push(10);
	a.push(-20);
	a.push(-40);

	MutantStack<int, std::vector<int> >::const_iterator it;

	it = a.begin();
	while (it < a.end())
	{	
		std::cout << *it << ", ";
		it++;
	}

	std::cout <<"\n";
	MutantStack<int, std::vector<int> >::const_reverse_iterator rit;
	rit = a.rbegin();
	while (rit < a.rend())
	{	
		std::cout << *rit << ", ";
		rit++;
	}

	// a.push(3);
	// MutantStack<int> b;
	//
	// b = a;
	// std::cout << "b.top() = " << b.top() << "\n";
}

// given main
/*
int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
	std::cout << "element in the mutant stack:\n";
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
std::cout << "s.top() = " << s.top() << "\n";
std::cout << "mstack.top() = " << mstack.top() << "\n";
return 0;
}
*/


// given main with list as container
/* 
int main()
{
MutantStack<int, std::list<int> > mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int, std::list<int> >::iterator it = mstack.begin();
MutantStack<int, std::list<int> >::iterator ite = mstack.end();
++it;
--it;
	std::cout << "element in the mutant stack:\n";
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int, std::list<int> > s(mstack);
std::cout << "s.top() = " << s.top() << "\n";
std::cout << "mstack.top() = " << mstack.top() << "\n";
return 0;
}
*/
