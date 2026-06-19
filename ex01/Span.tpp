/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:20:14 by jweber            #+#    #+#             */
/*   Updated: 2026/06/19 19:20:17 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template< typename InputIt >
void			Span::addNumberMultiple(InputIt first, InputIt last)
{
	for (InputIt tmp = first; tmp != last; tmp++)
	{
		this->addNumber(*tmp);
	}
}
