/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:46:14 by jgo               #+#    #+#             */
/*   Updated: 2023/07/24 09:46:48 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static inline void printSpan(void) {
	std::cout << " ______     ______   ______     __   __    \n";
	std::cout << "/\\  ___\\   /\\  == \\ /\\  __ \\   /\\ \"-.\\ \\   \n";
	std::cout << "\\ \\___  \\  \\ \\  _-/ \\ \\  __ \\  \\ \\ \\-.  \\  \n";
	std::cout << " \\/\\_____\\  \\ \\_\\    \\ \\_\\ \\_\\  \\ \\_\\\\\"\\_\\ \n";
	std::cout << "  \\/_____/   \\/_/     \\/_/\\/_/   \\/_/ \\/_/  cpp version: " YELLOW << __cplusplus
			  << RESET "\n\n";
}

static inline void defaultTest(void) {
	Span sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(6);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static inline void rangeTest(void) {
	VEC_INT vec;
	Span sp(7);

	for (int i = 1; i <= 7; ++i)
		vec.push_back(i * i);
	sp.addRange(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static inline void intenseTest(void) {
	Span sp(10000);

	for (int i = 0; i < 10000; ++i) {
		sp.addNumber(i);
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static inline void errorTest(void) {
	try {
		Span sp(0);
		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Span sp(1);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Span sp(6);
		VEC_INT vec;

		for (int i = 1; i <= 7; ++i)
			vec.push_back(i * i);
		sp.addRange(vec.begin(), vec.end());
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

int main(void) {
	printSpan();
	try {
		defaultTest();
		rangeTest();
		intenseTest();
		errorTest();
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return (0);
}