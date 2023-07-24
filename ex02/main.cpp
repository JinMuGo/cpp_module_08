/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:49:46 by jgo               #+#    #+#             */
/*   Updated: 2023/07/24 11:37:59 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include "version.h"

static inline void _printMutantStack(void) {
	std::cout << "              _              _   __ _             _     \n";
	std::cout << "  /\\/\\  _   _| |_ __ _ _ __ | |_/ _\\ |_ __ _  ___| | __ \n";
	std::cout << " /    \\| | | | __/ _` | '_ \\| __\\ \\| __/ _` |/ __| |/ / \n";
	std::cout << "/ /\\/\\ \\ |_| | || (_| | | | | |__\\ \\ || (_| | (__|   <  \n";
	std::cout << "\\/    \\/\\__,_|\\__\\__,_|_| |_|\\__\\__/\\__\\__,_|\\___|_|\\_\\ \n\n";
}

static inline void _defaultTest(void) {
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
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

static inline void _myTest(void) {
	MutantStack<std::string> mstack;

	mstack.push("hi");
	mstack.push("i\'m jgo");
	mstack.push("it\'s a good day");

	MutantStack<std::string>::const_iterator it = mstack.cbegin();
	MutantStack<std::string>::const_iterator ite = mstack.cend();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<std::string> tmp(mstack);

	MutantStack<std::string>::const_iterator Tit = tmp.cbegin();
	MutantStack<std::string>::const_iterator Tite = tmp.cend();
	--Tite;
	while (Tit != Tite) {
		std::cout << *Tite << std::endl;
		--Tite;
	}
	std::cout << *Tite << std::endl;
}

static inline void _reverseTest(void) {
	MutantStack<float> mstack;

	mstack.push(42.0f);
	mstack.push(244.0f);
	mstack.push(12.0f);
	mstack.push(211.0f);

	MutantStack<float>::reverse_iterator rit = mstack.rbegin();
	MutantStack<float>::reverse_iterator rite = mstack.rend();

	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}
}

int main(void) {
	_printMutantStack();
	PRT_VER;
	try {
		_defaultTest();
		_myTest();
		_reverseTest();
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}