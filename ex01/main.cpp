/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:19:41 by jweber            #+#    #+#             */
/*   Updated: 2026/06/19 19:33:06 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <limits>
#include <list>
#include <vector>

//#include "Span.cpp"

# define MSG(function) \
std::cout << "~~~~~~~~~~~~~~~ " #function " ~~~~~~~~~~~~~~~~~~~~~\n";\
function;\
std::cout << "~~~~~~~~~~~~~~~ END ~~~~~~~~~~~~~~~~~~~~~\n\n\n";

# define NL std::cout << std::endl;

void test_basic(void);
void test_only_positive_value(void);
void test_only_negative_value(void);
void test_positive_and_negative_value(void);
void test_min_max(void);
void test_min_max_zero(void);
void test_copy_constructor(void);
void test_assignement_operator(void);
void test_too_much_element(void);
void test_longestSpan_no_element(void);
void test_shortestSpan_no_element(void);
void test_addNumbersMultiple(void);
void test_10000_numbers(void);
void test_10001_numbers(void);

int	main(void)
{
	MSG(test_basic());
	MSG(test_only_positive_value());
	MSG(test_only_negative_value());
	MSG(test_positive_and_negative_value());
	MSG(test_min_max());
	MSG(test_min_max_zero());
	MSG(test_copy_constructor());
	MSG(test_assignement_operator());
	MSG(test_too_much_element());
	MSG(test_longestSpan_no_element());
	MSG(test_shortestSpan_no_element());
	MSG(test_addNumbersMultiple());
	MSG(test_10000_numbers());
	MSG(test_10001_numbers());

	return (0);
}

void test_basic(void)
{
	try 
	{
		Span a(3);
		std::cout << "Span = " << a << "\n";
		a.addNumber(5);
		a.addNumber(3);
		std::cout << "Span = " << a << "\n";
		std::cout << "longestSpan = " << a.longestSpan() << "\n";
		std::cout << "shortestSpan = " << a.shortestSpan() << "\n";

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_only_positive_value(void)
{
	try 
	{
		Span a(6);
		a.addNumber(154);
		a.addNumber(124);
		a.addNumber(94);
		a.addNumber(614);
		a.addNumber(15);
		a.addNumber(1);
		std::cout << "Span = " << a << "\n";
		std::cout << "longestSpan = " << a.longestSpan() << "\n";
		std::cout << "shortestSpan = " << a.shortestSpan() << "\n";

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_only_negative_value(void)
{
	try 
	{
		Span a(6);
		a.addNumber(-154);
		a.addNumber(-124);
		a.addNumber(-94);
		a.addNumber(-614);
		a.addNumber(-15);
		a.addNumber(-1);
		std::cout << "Span = " << a << "\n";
		std::cout << "longestSpan = " << a.longestSpan() << "\n";
		std::cout << "shortestSpan = " << a.shortestSpan() << "\n";

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_positive_and_negative_value(void)
{
	try 
	{
		Span a(6);
		a.addNumber(-1);
		a.addNumber(66);
		a.addNumber(-37);
		a.addNumber(168);
		a.addNumber(-1237);
		a.addNumber(1169);
		std::cout << "Span = " << a << "\n";
		std::cout << "longestSpan = " << a.longestSpan() << "\n";
		std::cout << "shortestSpan = " << a.shortestSpan() << "\n";

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_min_max(void)
{
	try 
	{
		Span a(3);
		std::cout << "Span = " << a << "\n";
		a.addNumber(std::numeric_limits<int>::max());
		a.addNumber(std::numeric_limits<int>::min());
		std::cout << "Span = " << a << "\n";
		std::cout << "longestSpan = " << a.longestSpan() << "\n";
		std::cout << "shortestSpan = " << a.shortestSpan() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_min_max_zero(void)
{
	try 
	{
		Span a(3);
		std::cout << "Span = " << a << "\n";
		a.addNumber(std::numeric_limits<int>::max());
		a.addNumber(std::numeric_limits<int>::min());
		a.addNumber(0);
		std::cout << "Span = " << a << "\n";
		std::cout << "longestSpan = " << a.longestSpan() << "\n";
		std::cout << "shortestSpan = " << a.shortestSpan() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_copy_constructor(void)
{
	try 
	{
		Span span(3);
		span.addNumber(6);
		span.addNumber(7);
		span.addNumber(8);

		Span span_cpy(span);
		std::cout << "Span= " << span << "\n";
		std::cout << "Span_cpy = " << span_cpy << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_assignement_operator(void)
{
	try 
	{
		Span span(3);
		span.addNumber(6);
		span.addNumber(7);
		span.addNumber(8);

		Span span_assigned(4);

		span_assigned = span;
		std::cout << "Span= " << span << "\n";
		std::cout << "Span_assigned = " << span_assigned << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_too_much_element(void)
{
	try 
	{
		Span span(3);
		std::cout << "Span= " << span << "\n";
		span.addNumber(15);
		std::cout << "Span= " << span << "\n";
		span.addNumber(793);
		std::cout << "Span= " << span << "\n";
		span.addNumber(515);
		std::cout << "Span= " << span << "\n";
		span.addNumber(461);
		std::cout << "Span= " << span << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_longestSpan_no_element(void)
{
	try 
	{
		Span span(3);
		std::cout << "Span= " << span << "\n";
		std::cout << "longestSpan = " << span.longestSpan() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try 
	{
		Span span(3);
		span.addNumber(1);
		std::cout << "Span= " << span << "\n";
		std::cout << "longestSpan = " << span.longestSpan() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_shortestSpan_no_element(void)
{
	try 
	{
		Span span(3);
		std::cout << "Span= " << span << "\n";
		std::cout << "shortestSpan = " << span.shortestSpan() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try 
	{
		Span span(3);
		span.addNumber(1);
		std::cout << "Span= " << span << "\n";
		std::cout << "shortestSpan = " << span.shortestSpan() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_addNumbersMultiple(void)
{
	try 
	{
		std::list<int> a_list;
		std::srand(std::time(NULL));
		for (int i = 0; i < 5; i++)
		{
			a_list.push_back(std::rand() % 50);
		}

		std::vector<int> a_vec;
		std::srand(std::time(NULL));
		for (int i = 0; i < 5; i++)
		{
			a_vec.push_back(std::rand() % 50);
		}
		Span span(100);
		span.addNumberMultiple(a_vec.begin(), a_vec.end());
		span.addNumberMultiple(a_list.begin(), a_list.end());
		std::cout << "span = " << span << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_10000_numbers(void)
{
	try 
	{
		std::list<int> a_list;
		std::srand(std::time(NULL));
		for (int i = 0; i < 5000; i++)
		{
			a_list.push_back(std::rand());
		}

		std::vector<int> a_vec;
		std::srand(std::time(NULL));
		for (int i = 0; i < 5000; i++)
		{
			a_vec.push_back(std::rand());
		}
		Span span(10000);
		span.addNumberMultiple(a_vec.begin(), a_vec.end());
		span.addNumberMultiple(a_list.begin(), a_list.end());
		std::cout << "span = " << span << "\n";
		std::cout << "longestSpan = " << span.longestSpan() << "\n";
		std::cout << "shortestSpan = " << span.shortestSpan() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_10001_numbers(void)
{
	try 
	{
		std::list<int> a_list;
		std::srand(std::time(NULL));
		for (int i = 0; i < 5000; i++)
		{
			a_list.push_back(std::rand());
		}

		std::vector<int> a_vec;
		std::srand(std::time(NULL));
		for (int i = 0; i < 5001; i++)
		{
			a_vec.push_back(std::rand());
		}
		Span span(10000);
		span.addNumberMultiple(a_vec.begin(), a_vec.end());
		span.addNumberMultiple(a_list.begin(), a_list.end());
		std::cout << "span = " << span << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

/*
// given main
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
*/
