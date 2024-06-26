/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:51:44 by jgo               #+#    #+#             */
/*   Updated: 2023/07/25 13:46:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <list>
#include <vector>
#include "color.h"
#include "easyfind.tpp"
#include "version.h"

static inline void printTitle(void) {
	std::cout << " ______     ______     ______     __  __     ______   __     __   __     _____    \n";
	std::cout
		<< "/\\  ___\\   /\\  __ \\   /\\  ___\\   /\\ \\_\\ \\   /\\  ___\\ /\\ \\   /\\ \"-.\\ \\   /\\  __-.  \n";
	std::cout << "\\ \\  __\\   \\ \\  __ \\  \\ \\___  \\  \\ \\____ \\  \\ \\  __\\ \\ \\ \\  \\ \\ \\-.  \\  \\ \\ "
				 "\\/\\ \\ \n";
	std::cout << " \\ \\_____\\  \\ \\_\\ \\_\\  \\/\\_____\\  \\/\\_____\\  \\ \\_\\    \\ \\_\\  \\ \\_\\\\\"\\_\\  "
				 "\\ \\____- \n";
	std::cout << "  \\/_____/   \\/_/\\/_/   \\/_____/   \\/_____/   \\/_/     \\/_/   \\/_/ \\/_/   \\/____/ \n";
}

static inline void myTest(void) {
	std::vector<int> vec(10);
	std::deque<int> deq(15);

	for (int i = 0; i < 10; ++i) {
		vec.at(i) = i + 1;
	}
	testContainer(vec, 3);

	for (int i = 0; i < 15; ++i) {
		deq.at(i) = i * 2;
	}
	testContainer(deq, 8);
}

static inline void _errorTest(void) {
	std::vector<int> vec(0);
	std::list<int> list;

	list.push_back(-5);
	list.push_back(-3);
	list.push_back(1);
	list.push_back(3);
	list.push_back(5);
	testContainer(list, -1);

	testContainer(vec, 3);
}

int main(void) {
	printTitle();
	PRT_VER;
	try {
		myTest();
		_errorTest();
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}
