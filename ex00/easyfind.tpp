/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:39:29 by jgo               #+#    #+#             */
/*   Updated: 2023/07/25 13:46:32 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.h"

template <typename T>
T_CONST_IT inline easyfind(const T& cont, const int &val) {
	if (cont.size() == 0)
		throw std::runtime_error("the Container size is 0");
	T_CONST_IT it = std::find(cont.begin(), cont.end(), val);
	if (it == cont.end())
		throw std::runtime_error("Can't find value in Container");
	return (it);
}

template <typename T>
static inline void testContainer(const T& cont, const int findVal) {
	std::cout  << "\nwe will find a " RED << findVal << RESET "... let me see" << std::endl;
	try {
		T_CONST_IT it = easyfind(cont, findVal);
		std::cout << "The value " GREEN << findVal << RESET " is in position: " << std::distance(cont.begin(), it) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

#endif
